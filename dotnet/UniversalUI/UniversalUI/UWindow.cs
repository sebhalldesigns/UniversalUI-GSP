namespace UniversalUI;

public class UWindow {

    private IntPtr GWindowHandle;

    public int Width;
    public int Height;
    public string Title;
    
    public UWindow() {
        Width = 800;
        Height = 600;
        Title = "Window";

        GSPCore.GWindowInfo windowInfo = new GSPCore.GWindowInfo {
            width = Width,
            height = Height,
            title = Title
        };

        GWindowHandle = GSPCore.GWindow_Init(windowInfo);
        GSPCore.GWindow_SetResizeDelegate(GWindowHandle, ResizeDelegate);
    }

    // DELEGATE FORWARDING
    private void ResizeDelegate(IntPtr window, GSPCore.GWindowSize size) {
        WindowResized(size);
    }


    public virtual void WindowResized(GSPCore.GWindowSize size) {
    }


}