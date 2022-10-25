#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "MathUtil.generated.h"

class UBoxComponent;
class AActor;
class USplineComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UMathUtil : public UObject {
    GENERATED_BODY()
public:
    UMathUtil();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 StableRandomInteger(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static bool SphereTriangleOverlap(const FVector& Center, const float Radius, const FVector& A, const FVector& B, const FVector& C);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool SphereCapsuleIntersect(const FVector& Origin, float SphereRadius, const FTransform& CapsuleTransform, float CapsuleHalfHeight, float CapsuleRadius);
    
    UFUNCTION(BlueprintCallable)
    static void SmoothCDFloat(float Val, float ValRate, const float DeltaTime, float to, const float SmoothTime, float& OutVal, float& OutValRate);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool SegmentCapsuleIntersect(const FVector& Start, const FVector& End, const FTransform& CapsuleTransform, float CapsuleHalfHeight, float CapsuleRadius);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float ScaleValueByLevel(int32 Level, float Value, float Inc, float Exp);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool RayIntersectsSphere(const FVector& LineOrigin, const FVector& LineDirection, const FVector& Center, float Radius, float& Distance);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float NormalizeToRangeAndClamp(float Value, float Minimum, float Maximum);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPointInBounds(const FVector& Point, const FVector& Origin, const FVector& Extents);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsInsideBox(UBoxComponent* Box, const FVector& Point);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetRandomPointInsideSphere(float SphereRadius);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetRandomPointInsideHollowSphere(float MinimumRadius, float MaximumRadius);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetRandomPointInsideCircle(float CircleRadius);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetPointAlongCircle(float Radius, float Angle);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetHeading(const FVector& Direction);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetDistanceScalar(float CurrentDistance, float OptimalDistance, float TotalDistance);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetDirectionVector(float Heading);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FRotator GetCameraRelativeBasis(const FVector& UpAxis, const FRotator& CameraRotation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetAngleDiff(float A0, float A1);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetAngleBetween(FVector A0, FVector A1);
    
    UFUNCTION(BlueprintCallable)
    static float FindClosestPointOnSpline(USplineComponent* Spline, const FVector& PointInSpace, FVector& OutClosestPoint);
    
    UFUNCTION(BlueprintCallable)
    static bool FindBestFitPlane(const TArray<FVector>& Points, FVector& OutBase, FVector& OutNormal);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float ApplyMod(float Value, float Mod, float Scalar);
    
};

