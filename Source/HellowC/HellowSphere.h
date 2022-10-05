// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HellowSphere.generated.h"

UCLASS()
class HELLOWC_API AHellowSphere : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHellowSphere();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	class UTextRenderComponent* TextRenderComponent;

};
