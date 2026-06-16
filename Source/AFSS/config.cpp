class CfgPatches
{
    class AFSS
    {
        requiredAddons[] = {};
    };
};

class CfgMods
{
    class AFSS
    {
        type = "mod";
        name = "Auto-Forward Smart Speed";
        version = "1.0";
        hidePicture = 1;
        inputs = "AFSS\data\inputs.xml";
        author = "John2022FR";
        credits = "Based on QuickStep by GayCookie";
        dependencies[] =
        {
            "World",
            "Mission"
        };

        class defs
        {
            class worldScriptModule
            {
                value = "";
                files[] =
                {
                    "AFSS/scripts/4_World"
                };
            };

            class missionScriptModule
            {
                value = "";
                files[] =
                {
                    "AFSS/scripts/5_Mission"
                };
            };
        };
    };
};
