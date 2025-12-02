#include "Agent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"

AAgent::AAgent()
{
    PrimaryActorTick.bCanEverTick = true;

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
    RootComponent = MeshComp;
    MeshComp->SetSimulatePhysics(true);
    MeshComp->SetEnableGravity(true);
}

void AAgent::BeginPlay()
{
    Super::BeginPlay();
}

void AAgent::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    // Placeholder for environment logic (e.g., reward calculation)
}

TArray<float> AAgent::CollectObservations() const
{
    TArray<float> Obs;
    FVector Pos = GetActorLocation();
    FVector Vel = MeshComp->GetPhysicsLinearVelocity();
    Obs.Add(Pos.X); Obs.Add(Pos.Y); Obs.Add(Pos.Z);
    Obs.Add(Vel.X); Obs.Add(Vel.Y); Obs.Add(Vel.Z);
    return Obs;
}

void AAgent::OnActionReceived(const TArray<float>& Action)
{
    if (Action.Num() >= 2)
    {
        FVector Force(Action[0], Action[1], 0.0f);
        MeshComp->AddForce(Force);
    }
}
