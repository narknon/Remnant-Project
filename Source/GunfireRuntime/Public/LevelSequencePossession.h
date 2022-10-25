#pragma once
#include "CoreMinimal.h"
#include "MovieSceneObjectBindingID.h"
#include "UObject/NoExportTypes.h"
#include "MovieSceneSequenceID.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "LevelSequencePossession.generated.h"

class AActor;
class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FLevelSequencePossession {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Avatar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Possessor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneObjectBindingID BindingID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneSequenceID SequenceID;
    
    UPROPERTY(EditAnywhere)
    TMap<UPrimitiveComponent*, TEnumAsByte<ECollisionEnabled::Type>> CachedCollisionMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UPrimitiveComponent*, bool> CachedMipStreamingMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CachedNegativeBoundsExtension;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CachedPositiveBoundsExtension;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsRestricted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform CachedTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CachedTargetability;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EMovementMode> CachedMovementMode;
    
    FLevelSequencePossession();
};

