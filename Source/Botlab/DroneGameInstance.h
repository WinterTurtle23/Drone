// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DroneGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class BOTLAB_API UDroneGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	int32 Score=0;
	
};
