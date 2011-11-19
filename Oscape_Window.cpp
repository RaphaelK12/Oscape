///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  4 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Oscape_Window.h"

///////////////////////////////////////////////////////////////////////////

wxOscape::wxOscape( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	OSMenuBar = new wxMenuBar( 0 );
	this->SetMenuBar( OSMenuBar );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	OSToolSwitch = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	OSPanelPlugins = new wxPanel( OSToolSwitch, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );
	
	OSPluginToolbar = new wxToolBar( OSPanelPlugins, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL ); 
	OSPluginToolbar->AddTool( wxID_RESET, wxT("Reset"), wxBitmap( wxT("#112"), wxBITMAP_TYPE_RESOURCE ), wxNullBitmap, wxITEM_NORMAL, wxT("Selects the plugins from O's load-order"), wxEmptyString, NULL ); 
	OSPluginToolbar->AddTool( wxID_CLEAR, wxT("tool"), wxBitmap( wxT("#110"), wxBITMAP_TYPE_RESOURCE ), wxNullBitmap, wxITEM_NORMAL, wxT("Clears the selection"), wxEmptyString, NULL ); 
	OSPluginToolbar->AddTool( wxID_LOAD, wxT("Load"), wxBitmap( wxT("#103"), wxBITMAP_TYPE_RESOURCE ), wxNullBitmap, wxITEM_NORMAL, wxT("Loads your last saved state"), wxEmptyString, NULL ); 
	OSPluginToolbar->AddTool( wxID_SAVE, wxT("Save"), wxBitmap( wxT("#104"), wxBITMAP_TYPE_RESOURCE ), wxNullBitmap, wxITEM_NORMAL, wxT("Save your current state"), wxEmptyString, NULL ); 
	OSPluginToolbar->Realize();
	
	bSizer39->Add( OSPluginToolbar, 0, wxEXPAND, 5 );
	
	OSPluginAutosave = new wxCheckBox( OSPanelPlugins, wxID_ANY, wxT("Autosave selection on success"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer39->Add( OSPluginAutosave, 0, wxALIGN_BOTTOM|wxALL, 5 );
	
	bSizer36->Add( bSizer39, 0, wxEXPAND, 5 );
	
	OSPluginDir = new wxDirPickerCtrl( OSPanelPlugins, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DIR_MUST_EXIST|wxDIRP_USE_TEXTCTRL );
	bSizer36->Add( OSPluginDir, 0, wxALL|wxEXPAND, 5 );
	
	wxString OSPluginListChoices[] = { wxT("a.esp"), wxT("b.esp") };
	int OSPluginListNChoices = sizeof( OSPluginListChoices ) / sizeof( wxString );
	OSPluginList = new wxCheckListBox( OSPanelPlugins, wxID_ANY, wxDefaultPosition, wxDefaultSize, OSPluginListNChoices, OSPluginListChoices, 0 );
	OSPluginList->SetToolTip( wxT("The plug-ins which should be used to extract the height-field") );
	
	bSizer36->Add( OSPluginList, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );
	
	OSWorldspace = new wxComboBox( OSPanelPlugins, wxID_ANY, wxT("Tamriel"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	OSWorldspace->Append( wxT("Tamriel") );
	OSWorldspace->Append( wxT("SEWorld") );
	bSizer14->Add( OSWorldspace, 1, wxALL, 5 );
	
	OSWorldspaceFill = new wxButton( OSPanelPlugins, wxID_ANY, wxT("Fill"), wxDefaultPosition, wxDefaultSize, 0 );
	OSWorldspaceFill->Enable( false );
	OSWorldspaceFill->SetToolTip( wxT("Fill the worldspace-selector with the available ones from the plugin-list") );
	
	bSizer14->Add( OSWorldspaceFill, 0, wxALL, 5 );
	
	bSizer36->Add( bSizer14, 0, wxEXPAND, 5 );
	
	m_staticline7 = new wxStaticLine( OSPanelPlugins, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer36->Add( m_staticline7, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxHORIZONTAL );
	
	OSFileHeightfieldOut = new wxFilePickerCtrl( OSPanelPlugins, wxID_ANY, wxT("./Tamriel.land"), wxT("Select a file"), wxT("*.land;*.raw"), wxDefaultPosition, wxDefaultSize, wxFLP_OVERWRITE_PROMPT|wxFLP_SAVE|wxFLP_USE_TEXTCTRL );
	bSizer42->Add( OSFileHeightfieldOut, 1, wxALL, 5 );
	
	OSPluginExtract = new wxButton( OSPanelPlugins, wxID_ANY, wxT("Extract"), wxDefaultPosition, wxDefaultSize, 0 );
	OSPluginExtract->Enable( false );
	OSPluginExtract->SetToolTip( wxT("Extract the height-data to the given file") );
	
	bSizer42->Add( OSPluginExtract, 0, wxALL, 5 );
	
	bSizer36->Add( bSizer42, 0, wxEXPAND, 5 );
	
	OSPanelPlugins->SetSizer( bSizer36 );
	OSPanelPlugins->Layout();
	bSizer36->Fit( OSPanelPlugins );
	OSToolSwitch->AddPage( OSPanelPlugins, wxT("Active Plugins"), true );
	OSPanelHeightfield = new wxPanel( OSToolSwitch, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxVERTICAL );
	
	OSFileHeightfieldIn1 = new wxFilePickerCtrl( OSPanelHeightfield, wxID_ANY, wxT("./Tamriel.land"), wxT("Select a file"), wxT("*.land;*.raw"), wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL );
	bSizer37->Add( OSFileHeightfieldIn1, 0, wxALL|wxEXPAND, 5 );
	
	OSHeightfieldFirst1 = new wxStaticText( OSPanelHeightfield, wxID_ANY, wxT("Select a heightfield first"), wxDefaultPosition, wxDefaultSize, 0 );
	OSHeightfieldFirst1->Wrap( -1 );
	bSizer37->Add( OSHeightfieldFirst1, 0, wxALIGN_CENTER|wxALL, 25 );
	
	OSHeightfieldPreview = new wxPanel( OSPanelHeightfield, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE|wxTAB_TRAVERSAL );
	OSHeightfieldPreview->SetToolTip( wxT("ough preview of the height-field") );
	
	bSizer37->Add( OSHeightfieldPreview, 1, wxEXPAND | wxALL, 5 );
	
	OSHeightfieldInfos = new wxPropertyGrid(OSPanelHeightfield, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_BOLD_MODIFIED|wxPG_DEFAULT_STYLE);
	bSizer37->Add( OSHeightfieldInfos, 1, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );
	
	OSFilePoints1 = new wxFilePickerCtrl( OSPanelHeightfield, wxID_ANY, wxT("./Tamriel.pts"), wxT("Select a file"), wxT("*.pts"), wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL );
	bSizer19->Add( OSFilePoints1, 1, wxALL|wxEXPAND, 5 );
	
	OSPointsClear1 = new wxButton( OSPanelHeightfield, wxID_ANY, wxT("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	OSPointsClear1->Enable( false );
	OSPointsClear1->SetToolTip( wxT("Clear the points-file") );
	
	bSizer19->Add( OSPointsClear1, 0, wxALL, 5 );
	
	bSizer37->Add( bSizer19, 0, wxEXPAND, 5 );
	
	OSAdditionalPoints = new wxListCtrl( OSPanelHeightfield, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_LIST );
	bSizer37->Add( OSAdditionalPoints, 0, wxALL|wxEXPAND, 5 );
	
	m_staticline71 = new wxStaticLine( OSPanelHeightfield, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer37->Add( m_staticline71, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer421;
	bSizer421 = new wxBoxSizer( wxHORIZONTAL );
	
	OSBaseDirOut1 = new wxDirPickerCtrl( OSPanelHeightfield, wxID_ANY, wxT("./generated"), wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_USE_TEXTCTRL );
	bSizer421->Add( OSBaseDirOut1, 1, wxALL, 5 );
	
	OSHeightfieldAccept = new wxButton( OSPanelHeightfield, wxID_ANY, wxT("Accept"), wxDefaultPosition, wxDefaultSize, 0 );
	OSHeightfieldAccept->Enable( false );
	OSHeightfieldAccept->SetToolTip( wxT("Accept the current values and go to the generator-page") );
	
	bSizer421->Add( OSHeightfieldAccept, 0, wxALL, 5 );
	
	bSizer37->Add( bSizer421, 0, wxEXPAND, 5 );
	
	OSPanelHeightfield->SetSizer( bSizer37 );
	OSPanelHeightfield->Layout();
	bSizer37->Fit( OSPanelHeightfield );
	OSToolSwitch->AddPage( OSPanelHeightfield, wxT("Heightfield"), false );
	OSPanelGenerator = new wxPanel( OSToolSwitch, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	OSFileHeightfieldIn2 = new wxFilePickerCtrl( OSPanelGenerator, wxID_ANY, wxT("./Tamriel.land"), wxT("Select a file"), wxT("*.land;*.raw"), wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL );
	bSizer15->Add( OSFileHeightfieldIn2, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer191;
	bSizer191 = new wxBoxSizer( wxHORIZONTAL );
	
	OSFilePoints2 = new wxFilePickerCtrl( OSPanelGenerator, wxID_ANY, wxT("./Tamriel.pts"), wxT("Select a file"), wxT("*.pts"), wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL );
	bSizer191->Add( OSFilePoints2, 1, wxALL|wxEXPAND, 5 );
	
	OSPointsClear2 = new wxButton( OSPanelGenerator, wxID_ANY, wxT("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	OSPointsClear2->Enable( false );
	OSPointsClear2->SetToolTip( wxT("Clear the points-file") );
	
	bSizer191->Add( OSPointsClear2, 0, wxALL, 5 );
	
	bSizer15->Add( bSizer191, 0, wxEXPAND, 5 );
	
	OSHeightfieldFirst2 = new wxStaticText( OSPanelGenerator, wxID_ANY, wxT("Select a heightfield first"), wxDefaultPosition, wxDefaultSize, 0 );
	OSHeightfieldFirst2->Wrap( -1 );
	bSizer15->Add( OSHeightfieldFirst2, 1, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 25 );
	
	OSSelectGenerator = new wxScrolledWindow( OSPanelGenerator, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	OSSelectGenerator->SetScrollRate( 5, 5 );
	OSSelectGenerator->Hide();
	
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer10;
	gSizer10 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_staticText8 = new wxStaticText( OSSelectGenerator, wxID_ANY, wxT("Algorithm:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	gSizer10->Add( m_staticText8, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString OSAlgorithmChoices[] = { wxT("Data-dependent"), wxT("Delaunay") };
	int OSAlgorithmNChoices = sizeof( OSAlgorithmChoices ) / sizeof( wxString );
	OSAlgorithm = new wxChoice( OSSelectGenerator, wxID_ANY, wxDefaultPosition, wxDefaultSize, OSAlgorithmNChoices, OSAlgorithmChoices, 0 );
	OSAlgorithm->SetSelection( 0 );
	OSAlgorithm->SetToolTip( wxT("Data-dependent is best") );
	
	gSizer10->Add( OSAlgorithm, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText13 = new wxStaticText( OSSelectGenerator, wxID_ANY, wxT("Error selection:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	gSizer10->Add( m_staticText13, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString QSErrorChoices[] = { wxT("Sum of max. error"), wxT("Max of max. error"), wxT("Sum of errorÂ²"), wxT("Angle of normals") };
	int QSErrorNChoices = sizeof( QSErrorChoices ) / sizeof( wxString );
	QSError = new wxChoice( OSSelectGenerator, wxID_ANY, wxDefaultPosition, wxDefaultSize, QSErrorNChoices, QSErrorChoices, 0 );
	QSError->SetSelection( 2 );
	QSError->SetToolTip( wxT("Sum of errorÂ² is best") );
	
	gSizer10->Add( QSError, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText11 = new wxStaticText( OSSelectGenerator, wxID_ANY, wxT("Quality threshold from 1.0 to 0.0:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	gSizer10->Add( m_staticText11, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	OSQThreshold = new wxTextCtrl( OSSelectGenerator, wxID_ANY, wxT("0.95"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	OSQThreshold->SetToolTip( wxT("0.95 is best, 0.0 is completely data-dependent") );
	
	gSizer10->Add( OSQThreshold, 0, wxALL|wxEXPAND, 5 );
	
	OSSupersampling = new wxStaticText( OSSelectGenerator, wxID_ANY, wxT("Area threshold from 0.0 to inf.:"), wxDefaultPosition, wxDefaultSize, 0 );
	OSSupersampling->Wrap( -1 );
	OSSupersampling->SetToolTip( wxT("Maximum area allowed without super-sampling") );
	
	gSizer10->Add( OSSupersampling, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	OSAThreshold = new wxTextCtrl( OSSelectGenerator, wxID_ANY, wxT("1e30"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	OSAThreshold->SetToolTip( wxT("1e30 is default, when to supersample") );
	
	gSizer10->Add( OSAThreshold, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText12 = new wxStaticText( OSSelectGenerator, wxID_ANY, wxT("Termination at error:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	gSizer10->Add( m_staticText12, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	OSTermination = new wxTextCtrl( OSSelectGenerator, wxID_ANY, wxT("0.00"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	OSTermination->SetToolTip( wxT("Causes premature termination in case the error-threshold is reached") );
	
	gSizer10->Add( OSTermination, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText15 = new wxStaticText( OSSelectGenerator, wxID_ANY, wxT("Target of max. resolution:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	gSizer10->Add( m_staticText15, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	OSTarget = new wxComboBox( OSSelectGenerator, wxID_ANY, wxT("786432"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	OSTarget->Append( wxT("786432") );
	OSTarget->Append( wxT("393216") );
	OSTarget->Append( wxT("196608") );
	OSTarget->Append( wxT("98304") );
	OSTarget->Append( wxT("49152") );
	OSTarget->Append( wxT("24576") );
	OSTarget->Append( wxT("12288") );
	OSTarget->Append( wxT("131072") );
	OSTarget->Append( wxT("65536") );
	OSTarget->Append( wxT("32768") );
	OSTarget->Append( wxT("16384") );
	OSTarget->Append( wxT("8192") );
	OSTarget->Append( wxT("4096") );
	OSTarget->Append( wxT("2048") );
	OSTarget->SetToolTip( wxT("Number of points for the entire data-set") );
	
	gSizer10->Add( OSTarget, 0, wxALL|wxEXPAND, 5 );
	
	bSizer38->Add( gSizer10, 0, wxEXPAND, 5 );
	
	m_staticline3 = new wxStaticLine( OSSelectGenerator, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer38->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );
	
	OSMeshes = new wxCheckBox( OSSelectGenerator, wxID_ANY, wxT("Meshes"), wxDefaultPosition, wxDefaultSize, 0 );
	OSMeshes->SetValue(true); 
	OSMeshes->SetToolTip( wxT("Generate meshes") );
	
	bSizer38->Add( OSMeshes, 0, wxALL, 5 );
	
	OSPanelMeshes = new wxPanel( OSSelectGenerator, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSTATIC_BORDER|wxTAB_TRAVERSAL );
	OSPanelMeshes->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer70;
	bSizer70 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText16 = new wxStaticText( OSPanelMeshes, wxID_ANY, wxT("Resolutions:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer70->Add( m_staticText16, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	OSRes1 = new wxCheckBox( OSPanelMeshes, wxID_ANY, wxT("1/1"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	OSRes1->SetValue(true); 
	OSRes1->Enable( false );
	
	bSizer70->Add( OSRes1, 0, wxALL, 5 );
	
	OSRes2 = new wxCheckBox( OSPanelMeshes, wxID_ANY, wxT("1/2"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	OSRes2->SetValue(true); 
	bSizer70->Add( OSRes2, 0, wxALL, 5 );
	
	OSRes3 = new wxCheckBox( OSPanelMeshes, wxID_ANY, wxT("1/4"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	OSRes3->SetValue(true); 
	bSizer70->Add( OSRes3, 0, wxALL, 5 );
	
	OSRes4 = new wxCheckBox( OSPanelMeshes, wxID_ANY, wxT("1/8"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	OSRes4->SetValue(true); 
	bSizer70->Add( OSRes4, 0, wxALL, 5 );
	
	bSizer24->Add( bSizer70, 1, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer701;
	bSizer701 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText28 = new wxStaticText( OSPanelMeshes, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	bSizer701->Add( m_staticText28, 1, wxALL, 5 );
	
	OSRes5 = new wxCheckBox( OSPanelMeshes, wxID_ANY, wxT("1/16"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	OSRes5->SetValue(true); 
	bSizer701->Add( OSRes5, 0, wxALL, 5 );
	
	OSRes6 = new wxCheckBox( OSPanelMeshes, wxID_ANY, wxT("1/32"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	OSRes6->SetValue(true); 
	bSizer701->Add( OSRes6, 0, wxALL, 5 );
	
	OSRes7 = new wxCheckBox( OSPanelMeshes, wxID_ANY, wxT("1/64"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	OSRes7->SetValue(true); 
	bSizer701->Add( OSRes7, 0, wxALL, 5 );
	
	OSRes8 = new wxCheckBox( OSPanelMeshes, wxID_ANY, wxT("1/128"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	OSRes8->SetValue(true); 
	bSizer701->Add( OSRes8, 0, wxALL, 5 );
	
	bSizer24->Add( bSizer701, 1, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	bSizer141->Add( bSizer24, 0, wxEXPAND, 5 );
	
	m_staticline6 = new wxStaticLine( OSPanelMeshes, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer141->Add( m_staticline6, 0, wxEXPAND | wxALL, 5 );
	
	OSMeshBasin = new wxCheckBox( OSPanelMeshes, wxID_ANY, wxT("with ocean-basin"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	OSMeshBasin->SetToolTip( wxT("The ocean won't be cut of at 512 units") );
	
	bSizer141->Add( OSMeshBasin, 0, wxALL|wxRIGHT|wxEXPAND, 5 );
	
	OSMeshUVs = new wxCheckBox( OSPanelMeshes, wxID_ANY, wxT("with texture-coordinates (UVs)"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT|wxCHK_3STATE|wxCHK_ALLOW_3RD_STATE_FOR_USER );
	OSMeshUVs->SetToolTip( wxT("The meshes will contain UV-coordinates and don't require OBGE") );
	
	bSizer141->Add( OSMeshUVs, 0, wxALL|wxEXPAND, 5 );
	
	OSMeshOpt = new wxCheckBox( OSPanelMeshes, wxID_ANY, wxT("optimize for overdraw"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	OSMeshOpt->SetValue(true); 
	OSMeshOpt->SetToolTip( wxT("Optimize the meshes to render faster") );
	
	bSizer141->Add( OSMeshOpt, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText111 = new wxStaticText( OSPanelMeshes, wxID_ANY, wxT("Formats:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111->Wrap( -1 );
	bSizer17->Add( m_staticText111, 1, wxALL|wxEXPAND, 5 );
	
	OSMeshNIF = new wxCheckBox( OSPanelMeshes, wxID_ANY, wxT("NIF"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	OSMeshNIF->SetValue(true); 
	OSMeshNIF->SetToolTip( wxT("generate meshes in Oblivion's standard format") );
	
	bSizer17->Add( OSMeshNIF, 0, wxALL, 5 );
	
	OSMeshDX = new wxCheckBox( OSPanelMeshes, wxID_ANY, wxT("DirectX"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	OSMeshDX->SetValue(true); 
	OSMeshDX->SetToolTip( wxT("generate meshes in Direct-X format as well, requires OBGE") );
	
	bSizer17->Add( OSMeshDX, 0, wxALL, 5 );
	
	OSMeshOBJ = new wxCheckBox( OSPanelMeshes, wxID_ANY, wxT("Wavefront"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	OSMeshOBJ->SetToolTip( wxT("generate meshes in Wavefront-format if you want to import it into a 3D-package") );
	
	bSizer17->Add( OSMeshOBJ, 0, wxALL, 5 );
	
	bSizer141->Add( bSizer17, 1, wxEXPAND, 5 );
	
	OSPanelMeshes->SetSizer( bSizer141 );
	OSPanelMeshes->Layout();
	bSizer141->Fit( OSPanelMeshes );
	bSizer38->Add( OSPanelMeshes, 0, wxEXPAND | wxALL, 5 );
	
	OSNormals = new wxCheckBox( OSSelectGenerator, wxID_ANY, wxT("Normals"), wxDefaultPosition, wxDefaultSize, 0 );
	OSNormals->SetValue(true); 
	OSNormals->SetToolTip( wxT("Generate normal-maps") );
	
	bSizer38->Add( OSNormals, 0, wxALL, 5 );
	
	OSPanelNormals = new wxPanel( OSSelectGenerator, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSTATIC_BORDER|wxTAB_TRAVERSAL );
	OSPanelNormals->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	wxBoxSizer* bSizer1411;
	bSizer1411 = new wxBoxSizer( wxVERTICAL );
	
	OSNormalLow = new wxCheckBox( OSPanelNormals, wxID_ANY, wxT("low-resolution textures (512x512)"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	OSNormalLow->SetValue(true); 
	bSizer1411->Add( OSNormalLow, 0, wxALL|wxRIGHT|wxEXPAND, 5 );
	
	OSNormalRegular = new wxCheckBox( OSPanelNormals, wxID_ANY, wxT("standard-resolution textures (1024x1024)"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	OSNormalRegular->SetValue(true); 
	bSizer1411->Add( OSNormalRegular, 0, wxALL|wxEXPAND, 5 );
	
	OSNormalHigh = new wxCheckBox( OSPanelNormals, wxID_ANY, wxT("high-resolution textures (2048x20484)"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	OSNormalHigh->SetValue(true); 
	bSizer1411->Add( OSNormalHigh, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer171;
	bSizer171 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1111 = new wxStaticText( OSPanelNormals, wxID_ANY, wxT("Formats:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1111->Wrap( -1 );
	bSizer171->Add( m_staticText1111, 1, wxALL|wxEXPAND, 5 );
	
	OSNormalPPM = new wxCheckBox( OSPanelNormals, wxID_ANY, wxT("PPM"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	bSizer171->Add( OSNormalPPM, 0, wxALL, 5 );
	
	OSNormalDDS = new wxCheckBox( OSPanelNormals, wxID_ANY, wxT("DirectX"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	OSNormalDDS->SetValue(true); 
	bSizer171->Add( OSNormalDDS, 0, wxALL, 5 );
	
	OSNormalPNG = new wxCheckBox( OSPanelNormals, wxID_ANY, wxT("PNG"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	OSNormalPNG->SetValue(true); 
	bSizer171->Add( OSNormalPNG, 0, wxALL, 5 );
	
	bSizer1411->Add( bSizer171, 1, wxEXPAND, 5 );
	
	OSPanelNormals->SetSizer( bSizer1411 );
	OSPanelNormals->Layout();
	bSizer1411->Fit( OSPanelNormals );
	bSizer38->Add( OSPanelNormals, 0, wxALL|wxEXPAND, 5 );
	
	OSHeightmap = new wxCheckBox( OSSelectGenerator, wxID_ANY, wxT("Heightmaps"), wxDefaultPosition, wxDefaultSize, 0 );
	OSHeightmap->Enable( false );
	
	bSizer38->Add( OSHeightmap, 0, wxALL, 5 );
	
	OSPanelHeightmap = new wxPanel( OSSelectGenerator, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSTATIC_BORDER|wxTAB_TRAVERSAL );
	OSPanelHeightmap->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	OSPanelHeightmap->Hide();
	
	wxBoxSizer* bSizer14111;
	bSizer14111 = new wxBoxSizer( wxVERTICAL );
	
	OSHeightmapLow = new wxCheckBox( OSPanelHeightmap, wxID_ANY, wxT("low-resolution textures (512x512)"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	bSizer14111->Add( OSHeightmapLow, 0, wxALL|wxRIGHT|wxEXPAND, 5 );
	
	OSHeightmapRegular = new wxCheckBox( OSPanelHeightmap, wxID_ANY, wxT("standard-resolution textures (1024x1024)"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	bSizer14111->Add( OSHeightmapRegular, 0, wxALL|wxEXPAND, 5 );
	
	OSHeightmapHigh = new wxCheckBox( OSPanelHeightmap, wxID_ANY, wxT("high-resolution textures (2048x20484)"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	bSizer14111->Add( OSHeightmapHigh, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1711;
	bSizer1711 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText11111 = new wxStaticText( OSPanelHeightmap, wxID_ANY, wxT("Formats:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11111->Wrap( -1 );
	bSizer1711->Add( m_staticText11111, 1, wxALL|wxEXPAND, 5 );
	
	OSHeightmapPPM = new wxCheckBox( OSPanelHeightmap, wxID_ANY, wxT("PPM"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	bSizer1711->Add( OSHeightmapPPM, 0, wxALL, 5 );
	
	OSHeightmapDDS = new wxCheckBox( OSPanelHeightmap, wxID_ANY, wxT("DirectX"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	bSizer1711->Add( OSHeightmapDDS, 0, wxALL, 5 );
	
	OSHeightmapPNG = new wxCheckBox( OSPanelHeightmap, wxID_ANY, wxT("PNG"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	bSizer1711->Add( OSHeightmapPNG, 0, wxALL, 5 );
	
	bSizer14111->Add( bSizer1711, 1, wxEXPAND, 5 );
	
	OSPanelHeightmap->SetSizer( bSizer14111 );
	OSPanelHeightmap->Layout();
	bSizer14111->Fit( OSPanelHeightmap );
	bSizer38->Add( OSPanelHeightmap, 0, wxEXPAND | wxALL, 5 );
	
	OSSelectGenerator->SetSizer( bSizer38 );
	OSSelectGenerator->Layout();
	bSizer38->Fit( OSSelectGenerator );
	bSizer15->Add( OSSelectGenerator, 1, wxEXPAND | wxALL, 5 );
	
	m_staticline711 = new wxStaticLine( OSPanelGenerator, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer15->Add( m_staticline711, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer4211;
	bSizer4211 = new wxBoxSizer( wxHORIZONTAL );
	
	OSOverwrite = new wxCheckBox( OSPanelGenerator, wxID_ANY, wxT("Overwrite"), wxDefaultPosition, wxDefaultSize, 0 );
	OSOverwrite->SetToolTip( wxT("Overwrite all files, even if they'd be valid") );
	
	bSizer4211->Add( OSOverwrite, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	OSBaseDirOut2 = new wxDirPickerCtrl( OSPanelGenerator, wxID_ANY, wxT("./generated"), wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_USE_TEXTCTRL );
	bSizer4211->Add( OSBaseDirOut2, 1, wxALL, 5 );
	
	OSHeightfieldGenerate = new wxButton( OSPanelGenerator, wxID_ANY, wxT("Generate"), wxDefaultPosition, wxDefaultSize, 0 );
	OSHeightfieldGenerate->Enable( false );
	OSHeightfieldGenerate->SetToolTip( wxT("Extract the height-data to the given file") );
	
	bSizer4211->Add( OSHeightfieldGenerate, 0, wxALL, 5 );
	
	bSizer15->Add( bSizer4211, 0, wxEXPAND, 5 );
	
	OSPanelGenerator->SetSizer( bSizer15 );
	OSPanelGenerator->Layout();
	bSizer15->Fit( OSPanelGenerator );
	OSToolSwitch->AddPage( OSPanelGenerator, wxT("Generator"), false );
	OSPanelInstaller = new wxPanel( OSToolSwitch, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer151;
	bSizer151 = new wxBoxSizer( wxVERTICAL );
	
	OSBaseDirIn = new wxDirPickerCtrl( OSPanelInstaller, wxID_ANY, wxT("./generated"), wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DIR_MUST_EXIST|wxDIRP_USE_TEXTCTRL );
	bSizer151->Add( OSBaseDirIn, 0, wxALL|wxEXPAND, 5 );
	
	OSHeightfieldFirst3 = new wxStaticText( OSPanelInstaller, wxID_ANY, wxT("Select a directory first"), wxDefaultPosition, wxDefaultSize, 0 );
	OSHeightfieldFirst3->Wrap( -1 );
	bSizer151->Add( OSHeightfieldFirst3, 1, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 25 );
	
	OSInstallWS = new wxListbook( OSPanelInstaller, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLB_DEFAULT );
	OSInstallWS->Hide();
	
	m_scrolledWindow4 = new wxScrolledWindow( OSInstallWS, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow4->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* OSLevel0;
	OSLevel0 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow4, wxID_ANY, wxT("Level0") ), wxVERTICAL );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	OSInstallLevel0 = new wxCheckBox( m_scrolledWindow4, wxID_ANY, wxT("Install"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer28->Add( OSInstallLevel0, 0, wxALL, 5 );
	
	OSInstallLevel0UVs = new wxCheckBox( m_scrolledWindow4, wxID_ANY, wxT("with UVs"), wxDefaultPosition, wxDefaultSize, 0 );
	OSInstallLevel0UVs->Hide();
	
	bSizer28->Add( OSInstallLevel0UVs, 0, wxALL, 5 );
	
	OSLevel0->Add( bSizer28, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer4;
	gSizer4 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_staticText40 = new wxStaticText( m_scrolledWindow4, wxID_ANY, wxT("Mesh-resolution:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText40->Wrap( -1 );
	gSizer4->Add( m_staticText40, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString OSInstallLevel0MeshResChoices;
	OSInstallLevel0MeshRes = new wxChoice( m_scrolledWindow4, wxID_ANY, wxDefaultPosition, wxDefaultSize, OSInstallLevel0MeshResChoices, 0 );
	OSInstallLevel0MeshRes->SetSelection( 0 );
	gSizer4->Add( OSInstallLevel0MeshRes, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText401 = new wxStaticText( m_scrolledWindow4, wxID_ANY, wxT("Texture-resolution:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText401->Wrap( -1 );
	gSizer4->Add( m_staticText401, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString OSInstallLevel0TextResChoices;
	OSInstallLevel0TextRes = new wxChoice( m_scrolledWindow4, wxID_ANY, wxDefaultPosition, wxDefaultSize, OSInstallLevel0TextResChoices, 0 );
	OSInstallLevel0TextRes->SetSelection( 0 );
	gSizer4->Add( OSInstallLevel0TextRes, 0, wxALL|wxEXPAND, 5 );
	
	OSLevel0->Add( gSizer4, 0, wxEXPAND, 5 );
	
	bSizer52->Add( OSLevel0, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* OSLevel1;
	OSLevel1 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow4, wxID_ANY, wxT("Level1") ), wxVERTICAL );
	
	wxBoxSizer* bSizer281;
	bSizer281 = new wxBoxSizer( wxHORIZONTAL );
	
	OSInstallLevel1 = new wxCheckBox( m_scrolledWindow4, wxID_ANY, wxT("Install"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer281->Add( OSInstallLevel1, 0, wxALL, 5 );
	
	OSInstallLevel1UVs = new wxCheckBox( m_scrolledWindow4, wxID_ANY, wxT("with UVs"), wxDefaultPosition, wxDefaultSize, 0 );
	OSInstallLevel1UVs->Hide();
	
	bSizer281->Add( OSInstallLevel1UVs, 0, wxALL, 5 );
	
	OSLevel1->Add( bSizer281, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer41;
	gSizer41 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_staticText402 = new wxStaticText( m_scrolledWindow4, wxID_ANY, wxT("Mesh-resolution:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText402->Wrap( -1 );
	gSizer41->Add( m_staticText402, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString OSInstallLevel1MeshResChoices;
	OSInstallLevel1MeshRes = new wxChoice( m_scrolledWindow4, wxID_ANY, wxDefaultPosition, wxDefaultSize, OSInstallLevel1MeshResChoices, 0 );
	OSInstallLevel1MeshRes->SetSelection( 0 );
	gSizer41->Add( OSInstallLevel1MeshRes, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText4011 = new wxStaticText( m_scrolledWindow4, wxID_ANY, wxT("MTexture-resolution:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4011->Wrap( -1 );
	gSizer41->Add( m_staticText4011, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString OSInstallLevel1TextResChoices;
	OSInstallLevel1TextRes = new wxChoice( m_scrolledWindow4, wxID_ANY, wxDefaultPosition, wxDefaultSize, OSInstallLevel1TextResChoices, 0 );
	OSInstallLevel1TextRes->SetSelection( 0 );
	gSizer41->Add( OSInstallLevel1TextRes, 0, wxALL|wxEXPAND, 5 );
	
	OSLevel1->Add( gSizer41, 0, wxEXPAND, 5 );
	
	bSizer52->Add( OSLevel1, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* OSLevel2;
	OSLevel2 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow4, wxID_ANY, wxT("Level2") ), wxVERTICAL );
	
	wxBoxSizer* bSizer282;
	bSizer282 = new wxBoxSizer( wxHORIZONTAL );
	
	OSInstallLevel2 = new wxCheckBox( m_scrolledWindow4, wxID_ANY, wxT("Install"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer282->Add( OSInstallLevel2, 0, wxALL, 5 );
	
	OSInstallLevel2UVs = new wxCheckBox( m_scrolledWindow4, wxID_ANY, wxT("with UVs"), wxDefaultPosition, wxDefaultSize, 0 );
	OSInstallLevel2UVs->Hide();
	
	bSizer282->Add( OSInstallLevel2UVs, 0, wxALL, 5 );
	
	OSLevel2->Add( bSizer282, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer42;
	gSizer42 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_staticText403 = new wxStaticText( m_scrolledWindow4, wxID_ANY, wxT("Mesh-resolution:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText403->Wrap( -1 );
	gSizer42->Add( m_staticText403, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString OSInstallLevel2MeshResChoices;
	OSInstallLevel2MeshRes = new wxChoice( m_scrolledWindow4, wxID_ANY, wxDefaultPosition, wxDefaultSize, OSInstallLevel2MeshResChoices, 0 );
	OSInstallLevel2MeshRes->SetSelection( 0 );
	gSizer42->Add( OSInstallLevel2MeshRes, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText4012 = new wxStaticText( m_scrolledWindow4, wxID_ANY, wxT("Texture-resolution:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4012->Wrap( -1 );
	gSizer42->Add( m_staticText4012, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString OSInstallLevel2TextResChoices;
	OSInstallLevel2TextRes = new wxChoice( m_scrolledWindow4, wxID_ANY, wxDefaultPosition, wxDefaultSize, OSInstallLevel2TextResChoices, 0 );
	OSInstallLevel2TextRes->SetSelection( 0 );
	gSizer42->Add( OSInstallLevel2TextRes, 0, wxALL|wxEXPAND, 5 );
	
	OSLevel2->Add( gSizer42, 0, wxEXPAND, 5 );
	
	bSizer52->Add( OSLevel2, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* OSLevel3;
	OSLevel3 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow4, wxID_ANY, wxT("Level3") ), wxVERTICAL );
	
	wxBoxSizer* bSizer283;
	bSizer283 = new wxBoxSizer( wxHORIZONTAL );
	
	OSInstallLevel3 = new wxCheckBox( m_scrolledWindow4, wxID_ANY, wxT("Install"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer283->Add( OSInstallLevel3, 0, wxALL, 5 );
	
	OSInstallLevel3UVs = new wxCheckBox( m_scrolledWindow4, wxID_ANY, wxT("with UVs"), wxDefaultPosition, wxDefaultSize, 0 );
	OSInstallLevel3UVs->Hide();
	
	bSizer283->Add( OSInstallLevel3UVs, 0, wxALL, 5 );
	
	OSLevel3->Add( bSizer283, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer43;
	gSizer43 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_staticText404 = new wxStaticText( m_scrolledWindow4, wxID_ANY, wxT("Mesh-resolution:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText404->Wrap( -1 );
	gSizer43->Add( m_staticText404, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString OSInstallLevel3MeshResChoices;
	OSInstallLevel3MeshRes = new wxChoice( m_scrolledWindow4, wxID_ANY, wxDefaultPosition, wxDefaultSize, OSInstallLevel3MeshResChoices, 0 );
	OSInstallLevel3MeshRes->SetSelection( 0 );
	gSizer43->Add( OSInstallLevel3MeshRes, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText4013 = new wxStaticText( m_scrolledWindow4, wxID_ANY, wxT("Texture-resolution:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4013->Wrap( -1 );
	gSizer43->Add( m_staticText4013, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString OSInstallLevel3TextResChoices;
	OSInstallLevel3TextRes = new wxChoice( m_scrolledWindow4, wxID_ANY, wxDefaultPosition, wxDefaultSize, OSInstallLevel3TextResChoices, 0 );
	OSInstallLevel3TextRes->SetSelection( 0 );
	gSizer43->Add( OSInstallLevel3TextRes, 0, wxALL|wxEXPAND, 5 );
	
	OSLevel3->Add( gSizer43, 0, wxEXPAND, 5 );
	
	bSizer52->Add( OSLevel3, 0, wxEXPAND, 5 );
	
	m_scrolledWindow4->SetSizer( bSizer52 );
	m_scrolledWindow4->Layout();
	bSizer52->Fit( m_scrolledWindow4 );
	OSInstallWS->AddPage( m_scrolledWindow4, wxT("Tamriel"), false );
	#ifndef __WXGTK__ // Small icon style not supported in GTK
	wxListView* OSInstallWSListView = OSInstallWS->GetListView();
	long OSInstallWSFlags = OSInstallWSListView->GetWindowStyleFlag();
	OSInstallWSFlags = ( OSInstallWSFlags & ~wxLC_ICON ) | wxLC_SMALL_ICON;
	OSInstallWSListView->SetWindowStyleFlag( OSInstallWSFlags );
	#endif
	
	bSizer151->Add( OSInstallWS, 1, wxEXPAND | wxALL, 5 );
	
	m_staticline7111 = new wxStaticLine( OSPanelInstaller, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer151->Add( m_staticline7111, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer42111;
	bSizer42111 = new wxBoxSizer( wxHORIZONTAL );
	
	OSPlugoutDir = new wxDirPickerCtrl( OSPanelInstaller, wxID_ANY, wxT("./Data"), wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_USE_TEXTCTRL );
	bSizer42111->Add( OSPlugoutDir, 1, wxALL, 5 );
	
	OSHeightfieldInstall = new wxButton( OSPanelInstaller, wxID_ANY, wxT("Install"), wxDefaultPosition, wxDefaultSize, 0 );
	OSHeightfieldInstall->Enable( false );
	OSHeightfieldInstall->SetToolTip( wxT("Extract the height-data to the given file") );
	
	bSizer42111->Add( OSHeightfieldInstall, 0, wxALL, 5 );
	
	bSizer151->Add( bSizer42111, 0, wxEXPAND, 5 );
	
	OSPanelInstaller->SetSizer( bSizer151 );
	OSPanelInstaller->Layout();
	bSizer151->Fit( OSPanelInstaller );
	OSToolSwitch->AddPage( OSPanelInstaller, wxT("Installer"), false );
	
	bSizer1->Add( OSToolSwitch, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	OSStatusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxID_RESET, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxOscape::ResetPluginList ) );
	this->Connect( wxID_CLEAR, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxOscape::ClearPluginList ) );
	this->Connect( wxID_LOAD, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxOscape::LoadPluginList ) );
	this->Connect( wxID_SAVE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxOscape::SavePluginList ) );
	OSPluginAutosave->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxOscape::ChangeAutosave ), NULL, this );
	OSPluginDir->Connect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangePluginDir ), NULL, this );
	OSPluginList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( wxOscape::ChangeActivePlugins ), NULL, this );
	OSWorldspace->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( wxOscape::ChangeWorldspace ), NULL, this );
	OSWorldspaceFill->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxOscape::WorldspacesFromPlugins ), NULL, this );
	OSFileHeightfieldOut->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangeHeightfieldOut ), NULL, this );
	OSPluginExtract->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxOscape::HeightfieldExtract ), NULL, this );
	OSFileHeightfieldIn1->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangeHeightfieldIn1 ), NULL, this );
	OSHeightfieldPreview->Connect( wxEVT_PAINT, wxPaintEventHandler( wxOscape::PaintH ), NULL, this );
	OSFilePoints1->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangePointsIn1 ), NULL, this );
	OSPointsClear1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxOscape::ClearPoints1 ), NULL, this );
	OSBaseDirOut1->Connect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangeBaseDirOut1 ), NULL, this );
	OSHeightfieldAccept->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxOscape::HeightfieldAccept ), NULL, this );
	OSFileHeightfieldIn2->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangeHeightfieldIn2 ), NULL, this );
	OSFilePoints2->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangePointsIn2 ), NULL, this );
	OSPointsClear2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxOscape::ClearPoints2 ), NULL, this );
	OSQThreshold->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( wxOscape::CheckFloat ), NULL, this );
	OSAThreshold->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( wxOscape::CheckFloat ), NULL, this );
	OSTermination->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( wxOscape::CheckFloat ), NULL, this );
	OSTarget->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( wxOscape::ChangeTarget ), NULL, this );
	OSTarget->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( wxOscape::CheckInt ), NULL, this );
	OSMeshes->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxOscape::ChangeMeshes ), NULL, this );
	OSNormals->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxOscape::ChangeNormals ), NULL, this );
	OSHeightmap->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxOscape::ChangeHeightmap ), NULL, this );
	OSBaseDirOut2->Connect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangeBaseDirOut2 ), NULL, this );
	OSHeightfieldGenerate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxOscape::HeightfieldGenerate ), NULL, this );
	OSBaseDirIn->Connect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangeBaseDirIn ), NULL, this );
	OSPlugoutDir->Connect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangePlugoutDir ), NULL, this );
	OSHeightfieldInstall->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxOscape::HeightfieldInstall ), NULL, this );
}

wxOscape::~wxOscape()
{
	// Disconnect Events
	this->Disconnect( wxID_RESET, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxOscape::ResetPluginList ) );
	this->Disconnect( wxID_CLEAR, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxOscape::ClearPluginList ) );
	this->Disconnect( wxID_LOAD, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxOscape::LoadPluginList ) );
	this->Disconnect( wxID_SAVE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( wxOscape::SavePluginList ) );
	OSPluginAutosave->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxOscape::ChangeAutosave ), NULL, this );
	OSPluginDir->Disconnect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangePluginDir ), NULL, this );
	OSPluginList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( wxOscape::ChangeActivePlugins ), NULL, this );
	OSWorldspace->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( wxOscape::ChangeWorldspace ), NULL, this );
	OSWorldspaceFill->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxOscape::WorldspacesFromPlugins ), NULL, this );
	OSFileHeightfieldOut->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangeHeightfieldOut ), NULL, this );
	OSPluginExtract->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxOscape::HeightfieldExtract ), NULL, this );
	OSFileHeightfieldIn1->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangeHeightfieldIn1 ), NULL, this );
	OSHeightfieldPreview->Disconnect( wxEVT_PAINT, wxPaintEventHandler( wxOscape::PaintH ), NULL, this );
	OSFilePoints1->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangePointsIn1 ), NULL, this );
	OSPointsClear1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxOscape::ClearPoints1 ), NULL, this );
	OSBaseDirOut1->Disconnect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangeBaseDirOut1 ), NULL, this );
	OSHeightfieldAccept->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxOscape::HeightfieldAccept ), NULL, this );
	OSFileHeightfieldIn2->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangeHeightfieldIn2 ), NULL, this );
	OSFilePoints2->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangePointsIn2 ), NULL, this );
	OSPointsClear2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxOscape::ClearPoints2 ), NULL, this );
	OSQThreshold->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( wxOscape::CheckFloat ), NULL, this );
	OSAThreshold->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( wxOscape::CheckFloat ), NULL, this );
	OSTermination->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( wxOscape::CheckFloat ), NULL, this );
	OSTarget->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( wxOscape::ChangeTarget ), NULL, this );
	OSTarget->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( wxOscape::CheckInt ), NULL, this );
	OSMeshes->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxOscape::ChangeMeshes ), NULL, this );
	OSNormals->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxOscape::ChangeNormals ), NULL, this );
	OSHeightmap->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxOscape::ChangeHeightmap ), NULL, this );
	OSBaseDirOut2->Disconnect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangeBaseDirOut2 ), NULL, this );
	OSHeightfieldGenerate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxOscape::HeightfieldGenerate ), NULL, this );
	OSBaseDirIn->Disconnect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangeBaseDirIn ), NULL, this );
	OSPlugoutDir->Disconnect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( wxOscape::ChangePlugoutDir ), NULL, this );
	OSHeightfieldInstall->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxOscape::HeightfieldInstall ), NULL, this );
	
}

wxProgress::wxProgress( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 400,265 ), wxDefaultSize );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );
	
	m_panel9 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxVERTICAL );
	
	OSSubject1 = new wxStaticText( m_panel9, wxID_ANY, wxT("Mesh resolution X:"), wxDefaultPosition, wxDefaultSize, 0 );
	OSSubject1->Wrap( -1 );
	bSizer26->Add( OSSubject1, 0, wxALL, 5 );
	
	OSTask1 = new wxGauge( m_panel9, wxID_ANY, 100, wxDefaultPosition, wxSize( -1,25 ), wxGA_HORIZONTAL|wxGA_SMOOTH );
	bSizer26->Add( OSTask1, 0, wxALL|wxEXPAND, 5 );
	
	OSSubject2 = new wxStaticText( m_panel9, wxID_ANY, wxT("Line Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	OSSubject2->Wrap( -1 );
	bSizer26->Add( OSSubject2, 0, wxALL, 5 );
	
	OSTask2 = new wxGauge( m_panel9, wxID_ANY, 100, wxDefaultPosition, wxSize( -1,25 ), wxGA_HORIZONTAL|wxGA_SMOOTH );
	bSizer26->Add( OSTask2, 0, wxALL|wxEXPAND, 5 );
	
	wxGridSizer* gSizer6;
	gSizer6 = new wxGridSizer( 2, 2, 0, 25 );
	
	m_staticText25 = new wxStaticText( m_panel9, wxID_ANY, wxT("Running:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	gSizer6->Add( m_staticText25, 0, wxALL, 2 );
	
	OSRunning = new wxStaticText( m_panel9, wxID_ANY, wxT("00:00s"), wxDefaultPosition, wxDefaultSize, 0 );
	OSRunning->Wrap( -1 );
	gSizer6->Add( OSRunning, 0, wxALIGN_RIGHT|wxALL, 2 );
	
	m_staticText27 = new wxStaticText( m_panel9, wxID_ANY, wxT("Remaining:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	gSizer6->Add( m_staticText27, 0, wxALL, 2 );
	
	OSRemaining = new wxStaticText( m_panel9, wxID_ANY, wxT("00:00s"), wxDefaultPosition, wxDefaultSize, 0 );
	OSRemaining->Wrap( -1 );
	gSizer6->Add( OSRemaining, 0, wxALIGN_RIGHT|wxALL, 2 );
	
	m_staticText29 = new wxStaticText( m_panel9, wxID_ANY, wxT("Total:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	gSizer6->Add( m_staticText29, 0, wxALL, 2 );
	
	OSTotal = new wxStaticText( m_panel9, wxID_ANY, wxT("00:00s"), wxDefaultPosition, wxDefaultSize, 0 );
	OSTotal->Wrap( -1 );
	gSizer6->Add( OSTotal, 0, wxALIGN_RIGHT|wxALL, 1 );
	
	bSizer26->Add( gSizer6, 0, wxALIGN_CENTER, 5 );
	
	m_staticline7 = new wxStaticLine( m_panel9, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer26->Add( m_staticline7, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );
	
	OSPause = new wxButton( m_panel9, wxID_ANY, wxT("Pause"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer27->Add( OSPause, 0, wxALL, 5 );
	
	OSAbort = new wxButton( m_panel9, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer27->Add( OSAbort, 0, wxALL, 5 );
	
	bSizer26->Add( bSizer27, 0, wxALIGN_CENTER, 5 );
	
	m_panel9->SetSizer( bSizer26 );
	m_panel9->Layout();
	bSizer26->Fit( m_panel9 );
	bSizer25->Add( m_panel9, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( bSizer25 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( wxProgress::AbortProgress ) );
	this->Connect( wxEVT_IDLE, wxIdleEventHandler( wxProgress::IdleProgress ) );
	OSPause->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProgress::PauseProgress ), NULL, this );
	OSAbort->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProgress::AbortProgress ), NULL, this );
}

wxProgress::~wxProgress()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( wxProgress::AbortProgress ) );
	this->Disconnect( wxEVT_IDLE, wxIdleEventHandler( wxProgress::IdleProgress ) );
	OSPause->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProgress::PauseProgress ), NULL, this );
	OSAbort->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProgress::AbortProgress ), NULL, this );
	
}
