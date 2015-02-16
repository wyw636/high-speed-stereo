
enum VizzerMode
{
    VizzerMode2DView,
    VizzerMode3DView,
    VizzerModeCount
};

inline string modeName(VizzerMode mode)
{
    switch (mode)
    {
    case VizzerMode2DView: return "render";
    case VizzerMode3DView: return "synth";
    default: return "unknown mode";
    }
}

inline VizzerMode modeFromName(const string &name)
{
    if (name == "2DView") return VizzerMode2DView;
    if (name == "3DView") return VizzerMode3DView;
    cout << "unrecognized mode : " << name << endl;
    return VizzerMode2DView;
}

struct ConstantBufferData
{
    mat4f worldViewProj;
};

struct AppState
{
    AppState()
    {
        showBBoxes = false;
    }

    void updateModeInterface()
    {
        modeInterface = NULL;
        if (mode == VizzerMode2DView) modeInterface = &modeView2D;
        if (mode == VizzerMode3DView) modeInterface = &modeView3D;
        ui.sendMessage("helpText " + ml::util::replace(modeInterface->helpText(), ' ', '@'));
    }

    ml::UIConnection ui;
    EventMap eventMap;

    AssetRenderer renderer;

    bool showBBoxes;

    Cameraf camera;

    vector<D3D11TriMesh> objectBBoxes;

    VizzerMode mode;
    ModeView2D modeView2D;
    ModeView3D modeView3D;

    VizzerModeInterface *modeInterface;
};