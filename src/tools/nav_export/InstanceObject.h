#pragma once

#include "vec3.h"

struct Transformation
{
  vec3 Translation;
  vec3 Rotation;
  vec3 Scale;
};

struct InstanceObjectBase
{
  int32_t AssetType;
  uint32_t InstanceID;
  int32_t Name;
  Transformation Transformation;
};

struct InstanceObject : InstanceObjectBase
{
};

enum eModelConfigCollisionType : int32_t
{
  COLLISION_ATTRIBUTE_TYPE_None = 0x0,
  COLLISION_ATTRIBUTE_TYPE_Replace = 0x1,
  COLLISION_ATTRIBUTE_TYPE_Box = 0x2,
};

struct BgData : InstanceObject
{
  int32_t AssetPath;
  int32_t CollisionAssetPath;
  eModelConfigCollisionType CollisionType;
  uint32_t AttributeMask;
  uint32_t Attribute;
  int32_t CollisionConfig;
  int8_t IsVisible;
  uint8_t RenderShadowEnabled;
  uint8_t RenderLightShadowEnabled;
  uint8_t Padding00[1];
  float RenderModelClipRange;
};


struct RelativePositions
{
  int32_t Pos;
  int32_t PosCount;
};

enum PopType : uint32_t
{
  PopTypePC = 0x1,
  PopTypeNPC = 0x2,
  PopTypeBNPC = 0x2,
  PopTypeContent = 0x3,
};

struct PopRangeData : InstanceObject
{
  PopType popType;
  RelativePositions relativePositions;
  float innerRadiusRatio;
  uint8_t index;
  uint8_t padding00[3];
  uint32_t reserved;
};

struct PathControlPoint
{
  vec3 Translation;
  uint16_t PointID;
  int8_t Selected;
  uint8_t Padding00[1];
};

struct ServerPathData : InstanceObject
{
  int32_t ControlPoints;
  int32_t ControlPoint_Count;
  uint32_t Reserved1;
  uint32_t Reserved2;
};

enum eDoorState : int32_t
{
  Auto_0 = 0x1,
  Open = 0x2,
  Closed = 0x3,
};

enum eRotationState : int32_t
{
  Rounding = 0x1,
  Stopped = 0x2,
};

enum eTransformState : int32_t
{
  TransformStatePlay = 0x0,
  TransformStateStop = 0x1,
  TransformStateReplay = 0x2,
  TransformStateReset = 0x3,
};

enum eColorState : int32_t
{
  ColorStatePlay = 0x0,
  ColorStateStop = 0x1,
  ColorStateReplay = 0x2,
  ColorStateReset = 0x3,
};

struct SGData : InstanceObject
{
  int32_t AssetPath;
  eDoorState InitialDoorState;
  int32_t OverriddenMembers;
  int32_t OverriddenMember_Count;
  eRotationState InitialRotationState;
  int8_t RandomTimelineAutoPlay;
  int8_t RandomTimelineLoopPlayback;
  int8_t IsCollisionControllableWithoutEObj;
  uint8_t Padding00[1];
  uint32_t BoundClientPathInstanceID;
  int32_t MovePathSettings;
  int8_t NotCreateNavimeshDoor;
  uint8_t Padding01[3];
  eTransformState InitialTransformState;
  eColorState InitialColorState;
};

struct EObjData : InstanceObject
{
  uint32_t BaseId;
  uint32_t BoundInstanceID;
  uint32_t LinkedInstanceID;
  uint32_t Reserved1;
  uint32_t Reserved2;
};

enum TriggerBoxShape : int32_t
{
  TriggerBoxShapeBox = 0x1,
  TriggerBoxShapeSphere = 0x2,
  TriggerBoxShapeCylinder = 0x3,
  TriggerBoxShapeBoard = 0x4,
  TriggerBoxShapeMesh = 0x5,
  TriggerBoxShapeBoardBothSides = 0x6,
};

struct TriggerBoxInstanceObject
{
  TriggerBoxShape triggerBoxShape;
  int16_t priority;
  int8_t enabled;
  uint8_t padding;
  uint32_t reserved;
};

struct EventRangeData : InstanceObject
{
  TriggerBoxInstanceObject triggerBox;
};

struct MapRangeData : InstanceObject
{
  TriggerBoxInstanceObject triggerBoxType;
  uint32_t mapId;
  uint32_t placeNameBlock;
  uint32_t placeNameSpot;
  uint32_t bGM;
  uint32_t weather;
  uint32_t reserved;
  uint32_t reserved2;
  uint16_t reserved3;
  uint8_t housingBlockId;
  int8_t restBonusEffective;
  uint8_t discoveryIndex;
  int8_t mapEnabled;
  int8_t placeNameEnabled;
  int8_t discoveryEnabled;
  int8_t bGMEnabled;
  int8_t weatherEnabled;
  int8_t restBonusEnabled;
  int8_t bGMPlayZoneInOnly;
  int8_t liftEnabled;
  int8_t housingEnabled;
  uint16_t padding;
};


struct CollisionBoxData : InstanceObject
{
  TriggerBoxInstanceObject triggerBox;
  uint32_t m_attribute;
  uint32_t m_attributeMask;
  uint32_t m_resourceId;
  bool m_pushPlayerOut;
};

struct ExitRangeData : InstanceObject
{
  TriggerBoxInstanceObject triggerBoxType;
  uint32_t exitType;
  uint16_t zoneId;
  uint16_t destTerritoryType;
  int32_t index;
  uint32_t destInstanceObjectId;
  uint32_t returnInstanceObjectId;
  float direction;
  uint32_t reserved;
};
