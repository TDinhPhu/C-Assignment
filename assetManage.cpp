#include <stdio.h>
#include <string.h>

struct Home
{
    char addr[100];
    float acreage;
};

struct Car
{
    int ID;
    char model[50];
};

union AssetDetails
{
    struct Home home;
    struct Car car;
};

struct Asset
{
    int ID;
    float Value;
    union AssetDetails details;
};

void displayHomeDetails(struct Asset asset)
{
    printf("Asset ID: %d\n", asset.ID);
    printf("Value: %.2f\n", asset.Value);
    printf("Home Address: %s\n", asset.details.home.addr);
    printf("Acreage: %.2f\n", asset.details.home.acreage);
}

void displayCarDetails(struct Asset asset)
{
    printf("Asset ID: %d\n", asset.ID);
    printf("Value: %.2f\n", asset.Value);
    printf("Car ID: %d\n", asset.details.car.ID);
    printf("Model: %s\n", asset.details.car.model);
}

int main()
{
    struct Asset asset1;
    asset1.ID = 1;
    asset1.Value = 250000.0;
    strcpy(asset1.details.home.addr, "50 Cong Hoa");
    asset1.details.home.acreage = 200.0;

    struct Asset asset2;
    asset2.ID = 2;
    asset2.Value = 35000.0;
    asset2.details.car.ID = 1001;
    strcpy(asset2.details.car.model, "Toyota Camry");
    
    void (*displayAssetFunc)(struct Asset);
    displayAssetFunc = displayHomeDetails;
    displayAssetFunc(asset1);

    displayAssetFunc = displayCarDetails;
    displayAssetFunc(asset2);

    return 0;
}
