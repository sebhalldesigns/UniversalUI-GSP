namespace UniversalUI;

public class UApplication {

    private IntPtr GApplicationHandle;

    public string Title;
    public string Developer;
    public int MajorVersion;
    public int MinorVersion;

    public UApplication() {
        Title = "Application";
        Developer = "Developer";
        MajorVersion = 0;
        MinorVersion = 1;


        GSPCore.GApplicationInfo appInfo = new GSPCore.GApplicationInfo {
            title = Title,
            developer = Developer,
            majorVersion = MajorVersion,
            minorVersion = MinorVersion
        };

        GApplicationHandle = GSPCore.GApplication.GApplication_Init(appInfo);
        GSPCore.GApplication.GApplication_SetLaunchEvent(GApplicationHandle, this.LaunchEvent);

    }


    public int Run() {

        return GSPCore.GSPCore.GSPRun(GApplicationHandle);
    }


    // CALLBACKS

    public virtual void LaunchEvent() {
        
    }

}