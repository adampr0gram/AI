using UnrealBuildTool;
using System.IO;

public class AI : ModuleRules
{
    public AI(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
        PrivateDependencyModuleNames.AddRange(new string[] {  });

        // Add LibTorch include/lib path - update LIBTORCH_ROOT in Build/LibTorchPath.txt or set environment variable
        string LibTorchRoot = "$(LIBTORCH_ROOT)"; // replace at build time or set in environment
        if (File.Exists(Path.Combine(ModuleDirectory, "../../Build/LibTorchPath.txt")))
        {
            LibTorchRoot = File.ReadAllText(Path.Combine(ModuleDirectory, "../../Build/LibTorchPath.txt")).Trim();
        }

        if (!string.IsNullOrEmpty(LibTorchRoot))
        {
            PublicIncludePaths.Add(Path.Combine(LibTorchRoot, "include"));
            // Add libs as needed - placeholder
            // PublicAdditionalLibraries.Add(Path.Combine(LibTorchRoot, "lib", "torch.lib"));
        }
    }
}
