using System.Runtime.InteropServices;

namespace GSPCore;


public static class GSPCore {

    [DllImport("GSPCore", CallingConvention = CallingConvention.Cdecl)]
    public static extern int GSPRun(IntPtr app);
}


