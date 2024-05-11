using System.Runtime.InteropServices;

namespace GSPCore;

public enum GLogLevel {
    INFO,
    WARNING,
    FAIL
}


public static class GLog {

    [DllImport("GSPCore", CallingConvention = CallingConvention.Cdecl)]
    private static extern void GLogSimple(GLogLevel level, string message);

    public static void Log(GLogLevel level, string message) {
        GLogSimple(level, message);
    }
}
