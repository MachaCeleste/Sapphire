// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include "Manager/EventMgr.h"
#include <Actor/BNpc.h>
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/QuestMgr.h"

// Quest Script: ClsGla020_00253
// Quest Name: Way of the Gladiator
// Quest ID: 65789
// Start NPC: 1002277 (Lulutsu)
// End NPC: 1001739 (Mylla)

using namespace Sapphire;

class ClsGla020 : public Sapphire::ScriptAPI::QuestScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // UI8AL
    // UI8BH
    // UI8BL

    /// Countable Num: 1 Seq: 1 Event: 1 Listener: 1001739
    /// Countable Num: 3 Seq: 2 Event: 5 Listener: 351
    /// Countable Num: 3 Seq: 2 Event: 5 Listener: 385
    /// Countable Num: 3 Seq: 2 Event: 5 Listener: 205
    /// Countable Num: 0 Seq: 255 Event: 1 Listener: 1001739
    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
      Seq0 = 0,
      Seq1 = 1,
      Seq2 = 2,
      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
    static constexpr auto Actor0 = 1002277; // Lulutsu ( Pos: -97.520401 6.973330 23.605700  Teri: 131 )
    static constexpr auto Actor1 = 1001739; // Mylla ( Pos: -94.529701 6.499970 39.810699  Teri: 131 )
    static constexpr auto Enemy0 = 351; // Qiqirn Gullroaster
    static constexpr auto Enemy1 = 385; // Trenchclaw Sahagin ( Pos: 80.837502 68.925400 -218.042999  Teri: 134 )
    static constexpr auto Enemy2 = 205; // Mottled Eft ( Pos: 15.554700 0.648601 -59.534698  Teri: 141 )
    static constexpr auto LogmessageMonsterNotePageUnlock = 1010;
    //static constexpr auto Seq0Actor0 = 0;
    //static constexpr auto Seq1Actor1 = 1;
    //static constexpr auto Seq3Actor1 = 2;
    static constexpr auto UnlockImageMonsterNote = 32;

  public:
    ClsGla020() : Sapphire::ScriptAPI::QuestScript( 65789 ){}; 
    ~ClsGla020() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( World::Quest& quest, Entity::Player& player, uint64_t actorId ) override
  {
    switch( actorId )
    {
      case Actor0:
      {
        Scene00000( quest, player );
        break;
      }
      case Actor1:
      {
        if( quest.getSeq() == Seq1 )
          Scene00001( quest, player );
        else if( quest.getSeq() == SeqFinish )
          Scene00005( quest, player );
        break;
      }
    }
  }

  void onBNpcKill( World::Quest& quest, Entity::BNpc& bnpc, Entity::Player& player ) override
  {
    if( bnpc.getBNpcBaseId() != Enemy0 && bnpc.getBNpcBaseId() != Enemy1 && bnpc.getBNpcBaseId() != Enemy2 )
      return;


    auto currentKC351 = quest.getUI8AL() + 1;
    auto currentKC385 = quest.getUI8BH() + 1;
    auto currentKC205 = quest.getUI8BL() + 1;

    switch( bnpc.getBNpcBaseId() )
    {
      case Enemy0:
      {
        if( currentKC351 >= 3 )
        {
          quest.setUI8AL( currentKC351 );
          checkQuestCompletion( quest, player );
          eventMgr().sendEventNotice( player, getId(), 1, 2, currentKC351, 3 );
        }
        else if( currentKC351 < 3 )
        {
          quest.setUI8AL( currentKC351 );
          eventMgr().sendEventNotice( player, getId(), 1, 2, currentKC351, 3 );
        }

        break;
      }
      case Enemy1:
      {
        if( currentKC385 >= 3 )
        {
          quest.setUI8BH( currentKC385 );
          checkQuestCompletion( quest, player );
          eventMgr().sendEventNotice( player, getId(), 2, 2, currentKC385, 3 );
        }
        else if( currentKC385 < 3 )
        {
          quest.setUI8BH( currentKC385 );
          eventMgr().sendEventNotice( player, getId(), 2, 2, currentKC385, 3 );
        }

        break;
      }
      case Enemy2:
      {
        if( currentKC205 >= 3 )
        {
          quest.setUI8BL( currentKC205 );
          checkQuestCompletion( quest, player );
          eventMgr().sendEventNotice( player, getId(), 3, 2, currentKC205, 3 );
        }
        else if( currentKC205 < 3 )
        {
          quest.setUI8BL( currentKC205 );
          eventMgr().sendEventNotice( player, getId(), 3, 2, currentKC205, 3 );
        }

        break;
      }
    }
  }

  private:
    void checkQuestCompletion( World::Quest& quest, Entity::Player& player )
    {
      auto currentKC351 = quest.getUI8AL();
      auto currentKC385 = quest.getUI8BH();
      auto currentKC205 = quest.getUI8BL();

      if( currentKC351 == 3 && currentKC385 == 3 && currentKC205 == 3 )
      {
        quest.setUI8AL( 0 );
        quest.setUI8BH( 0 );
        quest.setUI8BL( 0 );
        quest.setSeq( SeqFinish );
      }
    }
  //////////////////////////////////////////////////////////////////////
  // Available Scenes in this quest, not necessarly all are used
  //////////////////////////////////////////////////////////////////////

  void Scene00000( World::Quest& quest, Entity::Player& player )
  {
    eventMgr().playQuestScene( player, getId(), 0, NONE, bindSceneReturn( &ClsGla020::Scene00000Return ) );
  }

  void Scene00000Return( World::Quest& quest, Entity::Player& player, const Event::SceneResult& result )
  {
    if( result.getResult( 0 ) == 1 ) // accept quest
    {
      quest.setSeq( Seq1 );
    }


  }

  //////////////////////////////////////////////////////////////////////

  void Scene00001( World::Quest& quest, Entity::Player& player )
  {
    eventMgr().playQuestScene( player, getId(), 1, FADE_OUT | HIDE_UI, bindSceneReturn( &ClsGla020::Scene00001Return ) );
    //eventMgr().playScene( player, getId(), 1, FADE_OUT | HIDE_UI );
  }

  void Scene00001Return( World::Quest& quest, Entity::Player& player, const Event::SceneResult& result )
  {
    if( result.getResult( 0 ) == 1 )// Said yes in the cutscene
    {
      quest.setSeq( Seq2 );
    }
  }

  //////////////////////////////////////////////////////////////////////

  void Scene00002( World::Quest& quest, Entity::Player& player )
  {
    eventMgr().playQuestScene( player, getId(), 2, NONE, bindSceneReturn( &ClsGla020::Scene00002Return ) );
  }

  void Scene00002Return( World::Quest& quest, Entity::Player& player, const Event::SceneResult& result )
  {


  }

  //////////////////////////////////////////////////////////////////////

  void Scene00003( World::Quest& quest, Entity::Player& player )
  {
    eventMgr().playQuestScene( player, getId(), 3, NONE, bindSceneReturn( &ClsGla020::Scene00003Return ) );
  }

  void Scene00003Return( World::Quest& quest, Entity::Player& player, const Event::SceneResult& result )
  {


  }

  //////////////////////////////////////////////////////////////////////

  void Scene00004( World::Quest& quest, Entity::Player& player )
  {
    eventMgr().playQuestScene( player, getId(), 4, NONE, bindSceneReturn( &ClsGla020::Scene00004Return ) );
  }

  void Scene00004Return( World::Quest& quest, Entity::Player& player, const Event::SceneResult& result )
  {


  }

  //////////////////////////////////////////////////////////////////////

  void Scene00005( World::Quest& quest, Entity::Player& player )
  {
    eventMgr().playQuestScene( player, getId(), 5, NONE, bindSceneReturn( &ClsGla020::Scene00005Return ) );
  }

  void Scene00005Return( World::Quest& quest, Entity::Player& player, const Event::SceneResult& result )
  {

    if( result.getResult( 0 ) == 1 )
    {
      auto questMgr = Common::Service< World::Manager::QuestMgr >::ref();
      //if( player.giveQuestRewards( getId(), 0, result.getResult( 1 ) )
      if( questMgr.giveQuestRewards( player, getId(), 0 ) )
        player.finishQuest( getId(), result.getResult( 1 ) );
      //player.finishQuest( getId() );
    }

  }

};

EXPOSE_SCRIPT( ClsGla020 );