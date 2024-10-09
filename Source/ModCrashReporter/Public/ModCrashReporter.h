// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include <SMLConfiguration.h>

class FModCrashReporterModule : public IModuleInterface
{
public:
    /**
    * List of all user accepted crash reporting endpoints.
    * If any mod defines a Crash Reporting Endpoint URL that is contained within this list,
    * the modding crash reporter will send a crash report to the URL if possible without further notice to the user.
    */
    TArray<FString> AcceptedCrashReportingEndpoints;

    /**
    * List of user rejected crash reporting endpoints.
    * Opposite to AcceptedCrashReportingEndpoints.
    * Necessary to not repeat asking a user for the same endpoint multiple times between sessions.
    */
    TArray<FString> RejectedCrashReportingEndpoints;

    /**
    * If enabled, disables the custom satisfactory modding crash reporter and no crash reports will ever be sent
    * to any of the mods nor the modding infrastructure maintainers.
    */
    bool bDisableModdingCrashReporter;

public:
    /** Deserializes configuration from JSON object */
    static void ReadFromJson(const TSharedPtr<class FJsonObject>& Json, FSMLConfiguration& OutConfiguration, bool* OutIsMissingSections = NULL);

    /** Serializes configuration into JSON object */
    static void WriteToJson(const TSharedPtr<class FJsonObject>& OutJson, const FSMLConfiguration& Configuration);
    void StartupModule();
    void ShutdownModule();
};
