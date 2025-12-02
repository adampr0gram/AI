#pragma once
#include "CoreMinimal.h"
#include "Agent.h"
#include "torch/torch.h"
#include "RLTrainer.generated.h"

UCLASS()
class AI_API ARLTrainer : public AActor
{
    GENERATED_BODY()
public:
    ARLTrainer();
    virtual void Tick(float DeltaSeconds) override;
    virtual void BeginPlay() override;

    // Start a training episode loop (placeholder)
    void StartTraining();

protected:
    // Simple policy network (LibTorch) - placeholder
    std::shared_ptr<torch::nn::Module> PolicyNet;
    // Training loop helpers
    void Step();
};
