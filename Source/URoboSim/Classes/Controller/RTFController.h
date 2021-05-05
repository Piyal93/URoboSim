#include "RController.h"
// clang-format off
#include "RTFController.generated.h"
// clang-format on

USTRUCT()
struct FTFInfo
{
  GENERATED_BODY()
public:
  FString ParentFrame;
  FTransform Pose;
  // FString ChildFrame;
  // FORCEINLINE FTransform() : ParentFrame(""), Pose(FTransform()){};
  // FORCEINLINE explicit FTFInfo() : ParentFrame(InParentFrame), Pose(InPose){};
};

UCLASS()
class UROBOSIM_API URTFController : public URController
{
  GENERATED_BODY()

public:
  virtual void Init() override;

  virtual void AddTF(FString InFrameName, FTFInfo InTFInfo);

  virtual TMap<FString, FTFInfo> GetTFList();

  virtual bool UpdateFramePoses();

  virtual void SetLinkPose(URStaticMeshComponent *InChildLink, URStaticMeshComponent *InParentLink, FTransform InPose);

  virtual void Tick(const float &InDeltaTime) override;

protected:
  UPROPERTY(EditAnywhere)
  float UpdateRate;

  float Time;

  TMap<FString, FTFInfo> TFList;
};
