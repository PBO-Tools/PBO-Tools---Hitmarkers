class RustHitMarkersConfig: Managed {
    const static string ModProfileFolder = "$profile:SIXHitmarkers";
    const static string FileName = "/settings.json";
    const static string ConfigPath = ModProfileFolder + FileName;

    protected static autoptr RustHitMarkersConfig _singleton;

    private bool triggerOnAnimals;
    private bool triggerOnZombies;
    private bool triggerOnPlayers;

    static RustHitMarkersConfig GetInstance() {
        if (!_singleton)
            _singleton = new RustHitMarkersConfig();
        return _singleton;
    }

    void CreateConfig() {
        if (!GetGame().IsServer()) return;

        if (!FileExist(ModProfileFolder)) {
            Print("[SIXHitmarkers] '" + ModProfileFolder + "' does NOT exist, creating directory!");
            MakeDirectory(ModProfileFolder);
        }

        if (!FileExist(ConfigPath)) {
            Print("[SIXHitmarkers] '" + ConfigPath + "' does NOT exist, creating default config!");
            Default();
        }
        LoadConfig();
    }

    bool LoadConfig() {
        if (FileExist(ConfigPath)) {
            JsonFileLoader < RustHitMarkersConfig > .JsonLoadFile(ConfigPath, this);
            return true;
        }
        return false;
    }

    void Load() {
        CreateConfig();
        LoadConfig();
    }

    protected void Save() {
        JsonFileLoader < RustHitMarkersConfig > .JsonSaveFile(ConfigPath, this);
    }

    protected void Default() {
        triggerOnAnimals = true;
        triggerOnZombies = true;
        triggerOnPlayers = true;
        Save();
    }

    bool ShouldTrigger(Object entity) {
        if (entity.IsKindOf("AnimalBase")) return triggerOnAnimals;
        if (entity.IsKindOf("ZombieBase")) return triggerOnZombies;
        if (entity.IsKindOf("PlayerBase")) return triggerOnPlayers;
        return false;
    }
};

static autoptr RustHitMarkersConfig rustConfig;

static autoptr RustHitMarkersConfig GetRustHitMarkersConfig() {
    if (!rustConfig) {
        rustConfig = RustHitMarkersConfig.GetInstance();
        rustConfig.Load();
    }
    return rustConfig;
}