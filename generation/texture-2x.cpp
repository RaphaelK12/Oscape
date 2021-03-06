/* Version: MPL 1.1/LGPL 3.0
 *
 * "The contents of this file are subject to the Mozilla Public License
 * Version 1.1 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
 * License for the specific language governing rights and limitations
 * under the License.
 *
 * The Original Code is Oscape.
 *
 * The Initial Developer of the Original Code is
 * Ethatron <niels@paradice-insight.us>. Portions created by The Initial
 * Developer are Copyright (C) 2011 The Initial Developer.
 * All Rights Reserved.
 *
 * Alternatively, the contents of this file may be used under the terms
 * of the GNU Library General Public License Version 3 license (the
 * "LGPL License"), in which case the provisions of LGPL License are
 * applicable instead of those above. If you wish to allow use of your
 * version of this file only under the terms of the LGPL License and not
 * to allow others to use your version of this file under the MPL,
 * indicate your decision by deleting the provisions above and replace
 * them with the notice and other provisions required by the LGPL License.
 * If you do not delete the provisions above, a recipient may use your
 * version of this file under either the MPL or the LGPL License."
 */

#include "../globals.h"
#include "../openmp.h"
#include "../scape/hfield.H"

#include "texture.hpp"
#include "geometry.hpp"
#include "rasterize.hpp"
#include "../io/texture.hpp"

int dmap_w;
int dmap_h;
float dmap_zmin;
float *dmap = NULL;

Real dmap_eval(int x,int y) {
  if( x>=0 && x<dmap_w && y>=0 && y<dmap_h )
    return dmap[y * dmap_w + x];
  else
    return dmap_zmin;
}

#ifdef	SPLIT_ON_INJECTION
void wrteNormals2(bool fmaps, bool nmaps, bool hmaps, const HField& hf, const char *pattern) {
#define ADJUSTMENT  0
    int ww = hf.getWidth () + ADJUSTMENT, www = ww + (ww - ADJUSTMENT);
    int hh = hf.getHeight() + ADJUSTMENT, hhh = hh + (hh - ADJUSTMENT);

    dmap = new float[www * hhh];
    dmap_zmin = (float)hf.zmin();
    dmap_w = www;
    dmap_h = hhh;

    if (!dmap) throw runtime_error("Failed to allocate upscaled heightmap");
    memset(dmap, 0, sizeof(float) * www * hhh);

    /* initialize progress */
    InitProgress(hh + hhh);

    SetTopic("Upscaling heightfield:");

#if 1
    omp_init_cancellation();
#pragma omp parallel for schedule(static, (PROGRESS + 1) >> 3) shared(dmap, hf)
    for (int h = 0; h < hh; h++) {
      omp_skip_cancellation();
      if (!(h & PROGRESS)) {
	logrf("%dx%d %f%%\r", www, hhh, (100.0f * h) / hh);

	/* advance progress */
	omp_catch_cancellation(SetProgress(0 + h));
      }

      for (int w = 0; w < ww; w++) {
	Real O = hf.getZ(w, h);

	Real A = (((w + 1) < ww) ? hf.getZ(w + 1, h) : O);
	Real B = (((h - 1) >  0) ? hf.getZ(w, h - 1) : O);
	Real C = (((w - 1) >  0) ? hf.getZ(w - 1, h) : O);
	Real D = (((h + 1) < hh) ? hf.getZ(w, h + 1) : O);

	Real X = (((w + 1) < ww && (h + 1) < hh) ? hf.getZ(w + 1, h + 1) : O);
	Real Y = (((w - 1) >  0 && (h - 1) >  0) ? hf.getZ(w - 1, h - 1) : O);
	Real Z = (((w - 1) >  0 && (h + 1) < hh) ? hf.getZ(w - 1, h + 1) : O);
	Real W = (((w + 1) < ww && (h - 1) >  0) ? hf.getZ(w + 1, h - 1) : O);

	/* build from all four surrounding samples
	 *
	 * +-------+-------+-------+-------+
	 * |       |       |       |       |
	 * |   O   |       |   A   |       |
	 * |       |       |       |       |
	 * +-------+-------+-------+-------+
	 * |       |       |       |       |
	 * |       |   M   |       |       |
	 * |       |       |       |       |
	 * +-------+-------+-------+-------+
	 * |       |       |       |       |
	 * |   D   |       |   X   |       |
	 * |       |       |       |       |
	 * +-------+-------+-------+-------+
	 * |       |       |       |       |
	 * |       |       |       |       |
	 * |       |       |       |       |
	 * +-------+-------+-------+-------+
	 */

	Real dAD = fabs(A - D); Real dOX = fabs(O - X); bool f3 = dAD > dOX;

	Real M = (f3 ? 0.66667f : 0.33333f) * 0.5f * (A + D) +
		 (f3 ? 0.33333f : 0.66667f) * 0.5f * (O + X);

	if (((h * 2 + 0) < hhh) && ((w * 2 + 0) < www))
	  dmap[(h * 2 + 0) * www + (w * 2 + 0)] = (float)O;
	if (((h * 2 + 1) < hhh) && ((w * 2 + 1) < www))
	  dmap[(h * 2 + 1) * www + (w * 2 + 1)] = (float)M;
      }
    }

    omp_end_cancellation();

#pragma omp parallel for schedule(static, (PROGRESS + 1) >> 3) shared(dmap, hf)
    for (int h = 0; h < hhh; h++) {
      omp_skip_cancellation();
      if (!(h & PROGRESS)) {
	logrf("%dx%d %f%%\r", www, hhh, (100.0f * h) / hhh);

	/* advance progress */
	omp_catch_cancellation(SetProgress(hh + h));
      }

      for (int w = (h & 1 ? 0 : 1); w < www; w += 2) {
	Real O = hf.getZ(w / 2, h / 2);

	Real A = (((w + 1) < www) ? dmap_eval(w + 1, h) : O);
	Real B = (((h - 1) >   0) ? dmap_eval(w, h - 1) : O);
	Real C = (((w - 1) >   0) ? dmap_eval(w - 1, h) : O);
	Real D = (((h + 1) < hhh) ? dmap_eval(w, h + 1) : O);

	/* build from all four surrounding samples
	 *
	 * +-------+-------+-------+-------+-------+
	 * |       |       |       |       |       |
	 * |   O   |   B   |       |       |       |
	 * |       |       |       |       |       |
	 * +-------+-------+-------+-------+-------+
	 * |       |       |       |       |       |
	 * |   C   |   M   |   A   |       |       |
	 * |       |       |       |       |       |
	 * +-------+-------+-------+-------+-------+
	 * |       |       |       |       |       |
	 * |       |   D   |       |       |       |
	 * |       |       |       |       |       |
	 * +-------+-------+-------+-------+-------+
	 * |       |       |       |       |       |
	 * |       |       |       |       |       |
	 * |       |       |       |       |       |
	 * +-------+-------+-------+-------+-------+
	 * |       |       |       |       |       |
	 * |       |       |       |       |       |
	 * |       |       |       |       |       |
	 * +-------+-------+-------+-------+-------+
	 */

	Real dAC = fabs(A - C); Real dDB = fabs(D - B); bool f3 = dAC > dDB;

	Real M = (f3 ? 0.66667f : 0.33333f) * 0.5f * (A + C) +
		 (f3 ? 0.33333f : 0.66667f) * 0.5f * (D + B);

	dmap[(h * www) + w] = (float)M;
      }
    }

    omp_end_cancellation();
#else
    Real factor1 = sqrtf(1*1+1*1);
    Real factor2 = sqrtf(1*1+3*3);
    Real factor3 = sqrtf(3*3+1*1);
    Real factor4 = sqrtf(3*3+3*3);
    Real factorn = (1.0 / factor1) + (1.0 / factor2) + (1.0 / factor3) + (1.0 / factor4);

    for (int h = 0; h < hh; h++) {
      if (!(h & PROGRESS))
        logrf("%dx%d %f%%\r", www, hhh, (100.0f * h) / hh);

      for (int w = 0; w < ww; w++) {
	Real O = hf.getZ(w, h);

	Real A = (((w + 1) < ww) ? hf.getZ(w + 1, h) : O);
	Real B = (((h - 1) >  0) ? hf.getZ(w, h - 1) : O);
	Real C = (((w - 1) >  0) ? hf.getZ(w - 1, h) : O);
	Real D = (((h + 1) < hh) ? hf.getZ(w, h + 1) : O);

	Real X = (((w + 1) < ww && (h + 1) < hh) ? hf.getZ(w + 1, h + 1) : O);
	Real Y = (((w - 1) >  0 && (h - 1) >  0) ? hf.getZ(w - 1, h - 1) : O);
	Real Z = (((w - 1) >  0 && (h + 1) < hh) ? hf.getZ(w - 1, h + 1) : O);
	Real W = (((w + 1) < ww && (h - 1) >  0) ? hf.getZ(w + 1, h - 1) : O);

#if 0
	/* build from all four surrounding samples
	 *
	 * +-------+-------+-------+-------+	factor1 = sqrtf(1*1+1*1);
	 * |       |       |       |       |    factor2 = sqrtf(1*1+3*3);
	 * |       |       |       |       |    factor3 = sqrtf(3*3+1*1);
	 * |       |       |       |       |    factor4 = sqrtf(3*3+3*3);
	 * +-------O-------+-------A-------+
	 * |       | \1    | --    |       |
	 * |       |   # / |   3   |       |
	 * |       |  /  \ |       |       |
	 * +-------+-------+-------+-------+
	 * |       | /     | \4    |       |
	 * |       |  2    |   \   |       |
	 * |       |/      |     \ |       |
	 * +-------D-------+-------X-------+
	 * |       |       |       |       |
	 * |       |       |       |       |
	 * |       |       |       |       |
	 * +-------+-------+-------+-------+
	 */
	Real tl = O / factor1 + C / factor2 + B / factor3 + Y / factor4;
	Real tr = O / factor1 + A / factor2 + B / factor3 + W / factor4;
	Real br = O / factor1 + A / factor2 + D / factor3 + X / factor4;
	Real bl = O / factor1 + C / factor2 + D / factor3 + Z / factor4;
#else
	/* build from the detected ridge */
//	Real dCB = C + B; Real dOY = O + Y; bool f1 = dCB > dOY;
//	Real dAB = A + B; Real dOW = O + W; bool f2 = dAB > dOW;
//	Real dAD = A + D; Real dOX = O + X; bool f3 = dAD > dOX;
//	Real dCD = C + D; Real dOZ = O + Z; bool f4 = dCD > dOZ;

	Real dCB = fabs(C - B); Real dOY = fabs(O - Y); bool f1 = dCB > dOY;
	Real dAB = fabs(A - B); Real dOW = fabs(O - W); bool f2 = dAB > dOW;
	Real dAD = fabs(A - D); Real dOX = fabs(O - X); bool f3 = dAD > dOX;
	Real dCD = fabs(C - D); Real dOZ = fabs(O - Z); bool f4 = dCD > dOZ;

	/* weight the ridge 1.0, weight the other 0.5 */
	Real tl = (f1 ? 1.0 : 0.5) * (O / factor1 + C / factor2 + B / factor3) +
		  (f1 ? 0.5 : 1.0) * (O / factor1 + Y / factor4);
	Real tr = (f2 ? 1.0 : 0.5) * (O / factor1 + A / factor2 + B / factor3) +
		  (f2 ? 0.5 : 1.0) * (O / factor1 + W / factor4);
	Real br = (f3 ? 1.0 : 0.5) * (O / factor1 + A / factor2 + D / factor3) +
		  (f3 ? 0.5 : 1.0) * (O / factor1 + X / factor4);
	Real bl = (f4 ? 1.0 : 0.5) * (O / factor1 + C / factor2 + D / factor3) +
		  (f4 ? 0.5 : 1.0) * (O / factor1 + Z / factor4);

	/* weight the ridge 1.0, weight the other 0.5 */
	tl /= (f1 ? 1.0 : 0.5) * (1.0 / factor1 + 1.0 / factor2 + 1.0 / factor3) +
	      (f1 ? 0.5 : 1.0) * (1.0 / factor1 + 1.0 / factor4);
	tr /= (f2 ? 1.0 : 0.5) * (1.0 / factor1 + 1.0 / factor2 + 1.0 / factor3) +
	      (f2 ? 0.5 : 1.0) * (1.0 / factor1 + 1.0 / factor4);
	br /= (f3 ? 1.0 : 0.5) * (1.0 / factor1 + 1.0 / factor2 + 1.0 / factor3) +
	      (f3 ? 0.5 : 1.0) * (1.0 / factor1 + 1.0 / factor4);
	bl /= (f4 ? 1.0 : 0.5) * (1.0 / factor1 + 1.0 / factor2 + 1.0 / factor3) +
	      (f4 ? 0.5 : 1.0) * (1.0 / factor1 + 1.0 / factor4);
#endif

	dmap[(h * 2 + 0) * www + (w * 2 + 0)] = (float)(tl / factorn);
	dmap[(h * 2 + 0) * www + (w * 2 + 1)] = (float)(tr / factorn);
	dmap[(h * 2 + 1) * www + (w * 2 + 0)] = (float)(bl / factorn);
	dmap[(h * 2 + 1) * www + (w * 2 + 1)] = (float)(br / factorn);
      }
    }
#endif

    // 1k == 32, 3k == 96, 512 == 16 */
    int resx = restx;
    int resy = resty;

    // round down, negative side would be smaller than positive side
    int offx = offtx;
    int offy = offty;

    int gw = www;
    int gh = hhh;

#define ADJUSTMENT  0
    ww = rasterx + ADJUSTMENT; www = ww + (ww - ADJUSTMENT);
    hh = rastery + ADJUSTMENT; hhh = hh + (hh - ADJUSTMENT);

    int rrasterx = rasterx * 2;
    int rrastery = rastery * 2;

    /* allocate persistant output-buffer */
    if (nmaps) {
      pD3DDevice->CreateTexture(www, hhh, 0, 0, D3DFMT_A16B16G16R16, D3DPOOL_MANAGED, &tnrm, NULL);
      if (!tnrm) throw runtime_error("Failed to allocate texture");
    }

    if (hmaps) {
      pD3DDevice->CreateTexture(www, hhh, 0, 0, D3DFMT_A16B16G16R16, D3DPOOL_MANAGED, &thgt, NULL);
      if (!thgt) throw runtime_error("Failed to allocate texture");
    }

    /* initialize progress */
    InitProgress((numty - minty) * (numtx - mintx), hhh);

    for (int ty = minty; ty < numty; ty++) {
    for (int tx = mintx; tx < numtx; tx++) {
      int coordx = (tx - offx) * resx;
      int coordy = (ty - offy) * resy;

      /* VBs starts on index 0 */
      unsigned int i = 0, idx = 0;

      Real zscale = (2.0f * sizescale) / heightscale;

      if (nmaps && !skipTexture(pattern, "_fn", coordx, coordy, min(resx, resy), true)) {
	/* lock persistant output-buffer */
	D3DLOCKED_RECT rnrm;
	tnrm->LockRect(0, &rnrm, NULL, 0);
	USHORT *mnrm = (USHORT *)rnrm.pBits;

	SetTopic("Calculating tile {%d,%d} normals:", coordx, coordy);

	/* extract values out of the tile-window */
#pragma omp parallel for schedule(static, (PROGRESS + 1) >> 3) shared(mnrm, hf)
	for (int lh = 0; lh < hhh; lh++) {
	  const int h = (ty * rrastery) + lh;

          omp_skip_cancellation();
	  if (!(lh & PROGRESS)) {
	    logrf("%02dx%02d [%dx%d] %f%%\r", ty, tx, hhh, www, (100.0f * h) / ((ty * rrastery) + hhh));

	    /* advance progress */
	    omp_catch_cancellation(SetProgress(-1, lh));
	  }

	  /* calculate pointer of writable position */
	  USHORT *wnrm = mnrm + (lh * www) * 4;

	  for (int lw = 0; lw < www; lw++) {
	    const int w = (tx * rrasterx) + lw;

	    Real O = dmap_eval(w, h);

	    Real A = (((w + 1) < gw) ? dmap_eval(w + 1, h) : O);
	    Real B = (((h - 1) >  0) ? dmap_eval(w, h - 1) : O);
	    Real C = (((w - 1) >  0) ? dmap_eval(w - 1, h) : O);
	    Real D = (((h + 1) < gh) ? dmap_eval(w, h + 1) : O);

	    Real X = (((w + 1) < gw && (h + 1) < gh) ? dmap_eval(w + 1, h + 1) : O);
	    Real Y = (((w - 1) >  0 && (h - 1) >  0) ? dmap_eval(w - 1, h - 1) : O);
	    Real Z = (((w - 1) >  0 && (h + 1) < gh) ? dmap_eval(w - 1, h + 1) : O);
	    Real W = (((w + 1) < gw && (h - 1) >  0) ? dmap_eval(w + 1, h - 1) : O);

	    Real dimH = 2.0f;
	    Real dimV = 2.0f / sqrt(2.0f);

#ifdef MULTI_HEIGHTFIELD
	    Real o;
	    Real p;
	    Real q;
	    Real r;

	    int ow = (tx * rasterx) + (w / 2);
	    int oh = (ty * rastery) + (h / 2);
	    switch (((h & 1) << 1) | ((w & 1) << 0)) {
	      case 0:
		p = (((ow - 1) >  0 && (oh - 1) >  0) ? hf.getZ(ow - 1, oh - 1) : O);
		o = (((ow - 0) >  0 && (oh - 0) >  0) ? hf.getZ(ow - 0, oh - 0) : O);
		r = (((ow - 0) >  0 && (oh - 1) >  0) ? hf.getZ(ow - 0, oh - 1) : O);
		q = (((ow - 1) >  0 && (oh - 0) >  0) ? hf.getZ(ow - 1, oh - 0) : O);
		break;
	      case 1:
		o = (((ow + 1) < ww && (oh - 0) >  0) ? hf.getZ(ow + 1, oh - 0) : O);
		p = (((ow + 0) >  0 && (oh - 1) < hh) ? hf.getZ(ow + 0, oh - 1) : O);
		q = (((ow + 0) >  0 && (oh - 0) >  0) ? hf.getZ(ow + 0, oh - 0) : O);
		r = (((ow + 1) < ww && (oh - 1) < hh) ? hf.getZ(ow + 1, oh - 1) : O);
		break;
	      case 2:
		p = (((ow - 1) >  0 && (oh + 0) >  0) ? hf.getZ(ow - 1, oh + 0) : O);
		o = (((ow - 0) >  0 && (oh + 1) < hh) ? hf.getZ(ow - 0, oh + 1) : O);
		r = (((ow - 0) >  0 && (oh + 0) >  0) ? hf.getZ(ow - 0, oh + 0) : O);
		q = (((ow - 1) >  0 && (oh + 1) >  0) ? hf.getZ(ow - 1, oh + 1) : O);
		break;
	      case 3:
		o = (((ow + 1) < ww && (oh + 1) < hh) ? hf.getZ(ow + 1, oh + 1) : O);
		p = (((ow + 0) < ww && (oh + 0) < hh) ? hf.getZ(ow + 0, oh + 0) : O);
		q = (((ow + 0) < ww && (oh + 1) < hh) ? hf.getZ(ow + 0, oh + 1) : O);
		r = (((ow + 1) < ww && (oh + 0) < hh) ? hf.getZ(ow + 1, oh + 0) : O);
		break;
	    }

	    Real dimO = 1.0 / sqrt(2.0);
#endif

	    /* horizontal distance == 1.0 */
	    Real n1x = -(A - C);//(C - A);
	    Real n1y =  (B - D);//(D - B);
	    Real n1z = zscale / (heightadjust2 * dimH);

	    /* vertical distance == sqrt(2.0) */
	    Real n2x = -(W - Z);//(Z - W);
	    Real n2y =  (Y - X);//(X - Y);
	    Real n2z = zscale / (heightadjust2 * dimV);

	    Real mag1 = sqrt((n1x * n1x) + (n1y * n1y) + (n1z * n1z));
	    Real mag2 = sqrt((n2x * n2x) + (n2y * n2y) + (n2z * n2z));

	    n1x /= mag1;
	    n1y /= mag1;
	    n1z /= mag1;

	    n2x /= mag2;
	    n2y /= mag2;
	    n2z /= mag2;

#ifdef MULTI_HEIGHTFIELD
	    /* lattice distance == 2.0 */
	    Real n3x = -(r - q);//(Z - W);
	    Real n3y =  (p - o);//(X - Y);
	    Real n3z = zscale / (heightadjust2 * dimO);

	    Real mag3 = sqrt((n3x * n3x) + (n3y * n3y) + (n3z * n3z));

	    n3x /= mag3;
	    n3y /= mag3;
	    n3z /= mag3;

	    /* weight the diagonal vector sqrt(2) less */
	    Real nx = (n1x + n2x / sqrt(2.0) + n3x / 4.0);
	    Real ny = (n1y + n2y / sqrt(2.0) + n3y / 4.0);
	    Real nz = (n1z + n2z / sqrt(2.0) + n3z / 4.0);
#else
	    /* weight the diagonal vector sqrt(2) less */
	    Real nx = (n1x + n2x / sqrt(2.0f));
	    Real ny = (n1y + n2y / sqrt(2.0f));
	    Real nz = (n1z + n2z / sqrt(2.0f));
#endif

	    Real mag = sqrt((nx * nx) + (ny * ny) + (nz * nz));

	    nx /= mag;
	    ny /= mag;
	    nz /= mag;

	    O = max(0x0000, min(0xFFFF, O));

	    /* serial write to persistant output-buffer */
	    *wnrm++ = (int)((((nx) * 0.5) + 0.5) * 0xFFFF); // R
	    *wnrm++ = (int)((((ny) * 0.5) + 0.5) * 0xFFFF); // G
	    *wnrm++ = (int)((((nz) * 0.5) + 0.5) * 0xFFFF); // B
	    *wnrm++ =                              0xFFFF ; // A
	  }
	}

	tnrm->UnlockRect(0);
        omp_end_cancellation();

	SetTopic("Writing tile {%d,%d} normals:", coordx, coordy);

	/* flush persistant output-buffer to disk */
	wrteTexture(tnrm, pattern, "_fn", coordx, coordy, min(resx, resy), true);
      } /* nmaps */

      if (hmaps && !skipTexture(pattern, "_fh", coordx, coordy, min(resx, resy), false)) {
	/* lock persistant output-buffer */
	D3DLOCKED_RECT rhgt;
	thgt->LockRect(0, &rhgt, NULL, 0);
	USHORT *mhgt = (USHORT *)rhgt.pBits;

	SetTopic("Rasterizing tile {%d,%d} faces:", coordx, coordy);

	/* allocate temporary rasterization buffer */
        hmap_w = www;
        hmap_h = hhh;
        hmap_o = new float[www * hhh]; memset(hmap_o, 0, sizeof(float) * www * hhh);

	/* rasterize all triangles in this tile */
	fiterator itf; size_t fsz = SectorFaceO[ty][tx].size(), f = 0;
	for (itf = SectorFaceO[ty][tx].begin(); itf != SectorFaceO[ty][tx].end(); itf++, f++) {
	  if (!(f & PROGRESS))
	    logrf("%02dx%02d [%dx%d] %f%% (rasterize %fu�)\r", ty, tx, hhh, www, (100.0f * f) / fsz, (*itf)->narea);

	  class objVertex *v0 = (*itf)->v[0];
	  class objVertex *v1 = (*itf)->v[1];
	  class objVertex *v2 = (*itf)->v[2];

	  Rasterizer::DrawTriangle(2.0, (*itf), v0, v1, v2);
	}

	SetTopic("Calculating tile {%d,%d} deviations:", coordx, coordy);

	float hdev_p = 0.0;
	float hdev_n = 0.0;

#pragma omp parallel for schedule(static, (PROGRESS + 1) >> 3) shared(mhgt, hf)
	for (int lh = 0; lh < hhh; lh++) {
	  const int h = (ty * rrastery) + lh;

          omp_skip_cancellation();
	  if (!(lh & PROGRESS)) {
	    logrf("%02dx%02d [%dx%d] %f%% (triangle)\r", ty, tx, hhh, www, (100.0f * h) / ((ty * rrastery) + hhh));

	    /* advance progress */
	    omp_catch_cancellation(SetProgress(-1, lh));
	  }

	  /* calculate pointer of writable position */
	  USHORT *whgt = mhgt + (lh * www) * 4;

	  for (int lw = 0; lw < www; lw++) {
	    const int w = (tx * rrasterx) + lw;

	    /* restore the normals */
	    float O  = hmap_o[(lh * hmap_w) + lw];

	    /* write interpolated TNB height-map ----------------------- */
	    float o = (float)dmap_eval(w, h) - O;

	    if (O > 0.0) {
	      hdev_p = max(o, hdev_p);
	      hdev_n = min(o, hdev_n);
	    }

	    /* difference heightmap (amplified) -----------------------
	    O = O * 0x100 + 0x8000; */
	    O = max(0x0000, min(0xFFFF, O + 0x8000));

	    /* serial write to persistant output-buffer */
	    *whgt++ = (int)((((O ) * 1.0f) + 0.0f) * 0x0001); // L
	    *whgt++ = (int)((((O ) * 1.0f) + 0.0f) * 0x0001); // L
	    *whgt++ = (int)((((O ) * 1.0f) + 0.0f) * 0x0001); // L
	    *whgt++ = (int)((((O ) * 1.0f) + 0.0f) * 0x0001); // L
	  }
	}

	delete[] hmap_o; hmap_o = NULL;

	logpf("%02dx%02d: Heightmap deviation is [%f,%f]\n", ty, tx, hdev_n, hdev_p);

	thgt->UnlockRect(0);
        omp_end_cancellation();

	SetTopic("Writing tile {%d,%d} deviations:", coordx, coordy);

	/* flush persistant output-buffer to disk */
	wrteTexture(thgt, pattern, "_fh", coordx, coordy, min(resx, resy), false);
      } /* fmaps */

      /* advance progress */
      SetProgress((numty - minty) * (ty - minty) + (tx - mintx) + 1);
  }
  }

  delete[] dmap; dmap = NULL;

  if (nmaps) tnrm->Release(); tnrm = NULL;
  if (hmaps) thgt->Release(); thgt = NULL;
}

void wrteNormals2(bool fmaps, bool nmaps, bool hmaps, const HField& hf) {
  wrteNormals2(fmaps, nmaps, hmaps, hf, "%02d.%02d.%02d.%02d");
}
#endif

void wrteColors2(bool cmaps, CView& cf, const char *pattern) {
  // 1k == 32, 3k == 96, 512 == 16 */
  int resx = restx;
  int resy = resty;

  // round down, negative side would be smaller than positive side
  int offx = offtx;
  int offy = offty;

#define ADJUSTMENT  0
  /* 1 more to align texels with coordinates (center) */
  int ww = rasterx + ADJUSTMENT, www = rasterx * 2 + ADJUSTMENT;
  int hh = rastery + ADJUSTMENT, hhh = rastery * 2 + ADJUSTMENT;

  int gw = cf.get_width();
  int gh = cf.get_height();

  int tw = gw / width ; assert(tw > 1);
  int th = gh / height; assert(th > 1);

  /* number of pixels to merge */
  int mw = tw >> 1; assert(mw >= 1);
  int mh = th >> 1; assert(mh >= 1);

  /* allocate persistant output-buffer */
  if (cmaps) {
    pD3DDevice->CreateTexture(www, hhh, 0, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, &tcol, NULL);
    if (!tcol) throw runtime_error("Failed to allocate texture");
  }

  /* initialize progress */
  InitProgress((numty - minty) * (numtx - mintx), hh);

  omp_init_cancellation();
  for (int ty = minty; ty < numty; ty++) {
  for (int tx = mintx; tx < numtx; tx++) {
    int coordx = (tx - offx) * resx;
    int coordy = (ty - offy) * resy;

    /* VBs starts on index 0 */
    unsigned int i = 0, idx = 0;

    if (cmaps && !skipTexture(pattern, "", coordx, coordy, min(resx, resy), false)) {
      /* lock persistant output-buffer */
      D3DLOCKED_RECT rcol;
      tcol->LockRect(0, &rcol, NULL, 0);
      UCHAR *mcol = (UCHAR *)rcol.pBits;

      SetTopic("Calculating tile {%d,%d} colors:", coordx, coordy);

      /* extract values out of the tile-window */
#pragma omp parallel for schedule(static, (PROGRESS + 1) >> 3) shared(mcol, cf) ordered
      for (int lh = 0; lh < hhh; lh++) {
	const int h = th * (ty * rastery) + mh * (lh);

	/* TODO: critical */
        omp_skip_cancellation();
	cf.set_row(h);
	if (!(lh & PROGRESS)) {
	  logrf("%02dx%02d [%dx%d] %f%%\r", ty, tx, hhh, www, (100.0f * h) / ((ty * rastery) + hh));

	  /* advance progress */
	  omp_catch_cancellation(SetProgress(-1, lh));
	}

	/* calculate pointer of writable position */
	UCHAR *wcol = mcol + (lh * www) * 4;

	for (int lw = 0; lw < www; lw++) {
	  const int w = tw * (tx * rasterx) + mw * (lw);

	  unsigned long R = 0;
	  unsigned long G = 0;
	  unsigned long B = 0;
	  unsigned long A = 0;

	  for (int kh = 0; kh < mh; kh++)
	  for (int kw = 0; kw < mw; kw++) {
	    unsigned long c = cf.eval(w + kw, h + kh);
	    unsigned char r = (c >> 24) & 0xFF;
	    unsigned char g = (c >> 16) & 0xFF;
	    unsigned char b = (c >>  8) & 0xFF;
	    unsigned char a =             0xFF;

	    R += r;
	    G += g;
	    B += b;
	    A += a;
	  }

	  R /= mw * mh;
	  G /= mw * mh;
	  B /= mw * mh;
	  A /= mw * mh;

	  /* serial write to persistant output-buffer */
	  *wcol++ = (UCHAR)B; // R
	  *wcol++ = (UCHAR)G; // G
	  *wcol++ = (UCHAR)R; // B
	  *wcol++ = (UCHAR)A; // A
	}
      }

      tcol->UnlockRect(0);
      omp_end_cancellation();

      SetTopic("Writing tile {%d,%d} colors:", coordx, coordy);

      /* flush persistant output-buffer to disk */
      wrteTexture(tcol, pattern, "", coordx, coordy, min(resx, resy), false);
    } /* cmaps */

    /* advance progress */
    SetProgress((numty - minty) * (ty - minty) + (tx - mintx) + 1);
  }
  }

  if (cmaps) tcol->Release(); tcol = NULL;
}

void wrteColors2(bool cmaps, CView& cf) {
  wrteColors2(cmaps, cf, "%02d.%02d.%02d.%02d");
}
