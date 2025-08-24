#pragma once

#include "GameObject.h"

namespace Sapphire::Entity
{

  class AreaObject : public GameObject
  {
  public:
    AreaObject( uint32_t actorId, uint32_t actionId, uint32_t actionPotency, uint32_t vfxId, float scale,
      GameObjectPtr pOwner, const Common::FFXIVARR_POSITION3& pos );

    void spawn( PlayerPtr pTarget ) override;

    void despawn( PlayerPtr pTarget ) override;

    uint32_t getOwnerId() const;

    Common::ObjKind getOwnerObjKind() const;

    void setOwnerId( uint32_t ownerId );

    uint32_t getActionId() const;

    uint32_t getActionPotency() const;

  protected:
    uint32_t m_actionId;
    uint32_t m_actionPotency;
    uint32_t m_ownerId;
    Common::ObjKind m_ownerObjKind;
    uint32_t m_vfxId;
    float m_scale;
  };
}