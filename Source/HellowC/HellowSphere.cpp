// Fill out your copyright notice in the Description page of Project Settings.



#include "HellowSphere.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/TextRenderComponent.h"





// Sets default values
AHelloSphere::AHelloSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent")); //SphereComponent ����

	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(220.0f);
	SphereComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	//��ü �޽ø� �����ϰ� �����Ѵ�
	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	SphereVisual->AttachTo(RootComponent);

	//Construction helper�� ����� �޽ÿ� ����ƽ �޽ø� �����Ѵ�.
	ConstructorHelpers::FObjectFinder<UStaticMesh> SphereAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));

	ConstructorHelpers::FObjectFinder<UMaterial> SphereMaterial(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel'"));

	//�޽� ������ �߰ߵƴٸ� �޽��� �Ӽ��� �����Ѵ�.
	if (SphereAsset.Succeeded())
	{
		SphereVisual->SetStaticMesh(SphereAsset.Object);
		SphereVisual->SetMaterial(0, SphereMaterial.Object);
		SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -50.0f));
	}

	//���̾� ��ƼŬ �ý��� �����ϱ� 
	UParticleSystemComponent* FireParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireParticles"));

	FireParticles->AttachTo(SphereVisual);
	FireParticles->bAutoActivate = true;

	//������Ʈ�� ���̾� ��ƼŬ �ý��� �����ϱ�
	ConstructorHelpers::FObjectFinder<UParticleSystem> FireVisual(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	if (FireVisual.Succeeded())
	{
		FireParticles->SetTemplate(FireVisual.Object);
	}

	//�ؽ�Ʈ ���� ������Ʈ �ʱ�ȭ
	TextRenderComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text"));

	TextRenderComponent->AttachTo(SphereVisual);

	TextRenderComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 110.0f));
	TextRenderComponent->SetYScale(2.0f);
	TextRenderComponent->SetXScale(2.0f);
	TextRenderComponent->SetVisibility(true);
	TextRenderComponent->SetText(NSLOCTEXT("AnyNs", "Any", "HelloWorld"));

	OnActorBeginOverlap.AddDynamic(this, &AHelloSphere::MyOnBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AHelloSphere::MyOnEndOverlap);

}

// Called when the game starts or when spawned
void AHelloSphere::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHelloSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHelloSphere::MyOnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	FString outputString;
	outputString = "Hellow" + OtherActor->GetName() + "!";
	TextRenderComponent->SetText(FText::FromString(outputString));
}

void AHelloSphere::MyOnEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	TextRenderComponent->SetText(NSLOCTEXT("AnyNs", "Any", "HellowWorld"));
}

