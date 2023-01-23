// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "MMDUserImportVMDSettings.generated.h"

UENUM()
enum class ECameraCutImportType
{
	OneFrameInterval UMETA(DisplayName = "One Frame Interval (Best for Sequencer)"),
	ConstantKey UMETA(DisplayName = "Constant Key (MMD 60 frame animtion method)"),
	ImportAsIs UMETA(DisplayName = "Import As Is (For 30 frame animtion)"),
};

UCLASS(config = EditorSettings, BlueprintType)
class UMmdUserImportVmdSettings final : public UObject
{
public:
	explicit UMmdUserImportVmdSettings(const FObjectInitializer& Initializer);

	GENERATED_BODY()

	/** Import Uniform Scale */
	UPROPERTY(EditAnywhere, config, Category = Import)
	float ImportUniformScale;

	/** Camera Cut Import Type */
	UPROPERTY(EditAnywhere, config, Category = Import)
	ECameraCutImportType CameraCutImportType;

	/** Add Motion Blur Key */
	UPROPERTY(EditAnywhere, config, Category = Import)
	bool bAddMotionBlurKey;

	/** Motion Blur Amount */
	UPROPERTY(EditAnywhere, config, Category = Import, meta = (EditCondition = "bAddMotionBlurKey"))
	float MotionBlurAmount;
};
