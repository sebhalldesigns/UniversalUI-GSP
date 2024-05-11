


class ExampleApp: UniversalUI.UApplication {



    public override void LaunchEvent() {
        Console.WriteLine("LAUNCHED IN EXAMPLE APP");

        UniversalUI.UWindow window = new UniversalUI.UWindow();
    }
}

class Program { 
  
    // Main Method 
    public static void Main(String[] args) { 
  
        UniversalUI.GSPCore.GLog(UniversalUI.GSPCore.GLogLevel.INFO, "SOME INFO FROM CSHARP");

        ExampleApp app = new ExampleApp();

        app.Run();
    } 
} 