#pragma once
#include "IComponent.h"
#include "Gameplay/Physics/RigidBody.h"
#include "GLFW/glfw3.h"

/// <summary>
/// Behavior that moves the vehicles in the scene
/// </summary>
class VehicleMover : public Gameplay::IComponent {
public:
	typedef std::shared_ptr<VehicleMover> Sptr;

	VehicleMover();
	virtual ~VehicleMover();

	virtual void Awake() override;
	virtual void Update(float deltaTime) override;


public:
	virtual void RenderImGui() override;
	MAKE_TYPENAME(VehicleMover);
	virtual nlohmann::json ToJson() const override;
	static VehicleMover::Sptr FromJson(const nlohmann::json& blob);



protected:
	float ObjY;
	float ObjZ;
	float ObjX;

	Gameplay::Physics::RigidBody::Sptr _body;

};