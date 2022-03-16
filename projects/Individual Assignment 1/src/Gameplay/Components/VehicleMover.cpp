#include "Gameplay/Components/VehicleMover.h"
#include <GLFW/glfw3.h>
#include "Gameplay/GameObject.h"
#include "Gameplay/Scene.h"
#include "Utils/ImGuiHelper.h"

void VehicleMover::Awake()
{
    _body = GetComponent<Gameplay::Physics::RigidBody>();
    if (_body == nullptr) {
        IsEnabled = false;
    }

}

void VehicleMover::RenderImGui() {

}

nlohmann::json VehicleMover::ToJson() const {
    return {
    };
}
// Constructor Initializes Values for LERP and Set Position but Only SetPosition is being used atm
VehicleMover::VehicleMover() :
    IComponent(),
    ObjY(0.0f),
    ObjZ(0.0f),
    ObjX(0.0f)
{ }

VehicleMover::~VehicleMover() = default;

VehicleMover::Sptr VehicleMover::FromJson(const nlohmann::json & blob) {
    VehicleMover::Sptr result = std::make_shared<VehicleMover>();
    return result;
}

void VehicleMover::Update(float deltaTime)
{
   // GetGameObject()->SetPostion(glm::vec3(30.0f, 10.0f, 2.0f));
   // std::cout << "Is this john working?" << std::endl;
    //LOG_INFO("Is this john working LOG");
    
    // Movement For Regular Car
    // Grabs the vehicle's Current position
    float BObjPosY = GetGameObject()->GetScene()->FindObjectByName("RegularCar")->GetPosition().y;

    ObjX = GetGameObject()->GetScene()->FindObjectByName("RegularCar")->GetPosition().x;
    ObjZ = GetGameObject()->GetScene()->FindObjectByName("RegularCar")->GetPosition().z;
    // Update this specific vehicle's position
    if (GetGameObject()->GetScene()->FindObjectByName("RegularCar"))
    {
        BObjPosY = BObjPosY - 5.0 * deltaTime;
        GetGameObject()->GetScene()->FindObjectByName("RegularCar")->SetPostion(glm::vec3(ObjX, BObjPosY, ObjZ));
    }
    //When this vehicle is greater than a certain amount reset it back to a starting position
    if (GetGameObject()->GetScene()->FindObjectByName("RegularCar")->GetPosition().y <= -40.0f)
    {
        GetGameObject()->GetScene()->FindObjectByName("RegularCar")->SetPostion(glm::vec3(-4.5f, 40.0f, 3.0f));
    }

    // Movement for Pickup Truck
    // Grabs the vehicle's Current position
    float pickupObjPosY = GetGameObject()->GetScene()->FindObjectByName("PickupTruck")->GetPosition().y;

    ObjX = GetGameObject()->GetScene()->FindObjectByName("PickupTruck")->GetPosition().x;
    ObjZ = GetGameObject()->GetScene()->FindObjectByName("PickupTruck")->GetPosition().z;
    // Update this specific vehicle's position
    if (GetGameObject()->GetScene()->FindObjectByName("PickupTruck"))
    {
        pickupObjPosY = pickupObjPosY - 5.0 * deltaTime;
        GetGameObject()->GetScene()->FindObjectByName("PickupTruck")->SetPostion(glm::vec3(ObjX, pickupObjPosY, ObjZ));
    }
    //When this vehicle is greater than a certain amount reset it back to a starting position
    if (GetGameObject()->GetScene()->FindObjectByName("PickupTruck")->GetPosition().y <= -40.0f)
    {
        GetGameObject()->GetScene()->FindObjectByName("PickupTruck")->SetPostion(glm::vec3(-4.5f, 40.0f, 2.0f));
    }

    // Movement for SemiTruck
    // Grabs the vehicle's Current position
    float semiObjPosY = GetGameObject()->GetScene()->FindObjectByName("SemiTruck")->GetPosition().y;

    ObjX = GetGameObject()->GetScene()->FindObjectByName("SemiTruck")->GetPosition().x;
    ObjZ = GetGameObject()->GetScene()->FindObjectByName("SemiTruck")->GetPosition().z;
    // Update this specific vehicle's position
    if (GetGameObject()->GetScene()->FindObjectByName("SemiTruck"))
    {
        semiObjPosY = semiObjPosY + 5.0 * deltaTime;
        GetGameObject()->GetScene()->FindObjectByName("SemiTruck")->SetPostion(glm::vec3(ObjX, semiObjPosY, ObjZ));
    }
    //When this vehicle is greater than a certain amount reset it back to a starting position
    if (GetGameObject()->GetScene()->FindObjectByName("SemiTruck")->GetPosition().y >= 40.0f)
    {
        GetGameObject()->GetScene()->FindObjectByName("SemiTruck")->SetPostion(glm::vec3(10.5f, -40.0f, 2.0f));
    }
}