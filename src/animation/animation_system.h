#pragma once


#include "core/lux.h"
#include "engine/iplugin.h"


namespace Lux
{
	namespace FS
	{
		class FileSystem;
	};


	class Animation;
	class Engine;
	struct Entity;
	class ISerializer;
	class Universe;

	class LUX_ENGINE_API AnimationSystem : public IPlugin
	{
		public:
			AnimationSystem() { m_impl = 0; }

			virtual bool create(Engine&) override;
			virtual void update(float time_delta) override;
			virtual void onCreateUniverse(Universe& universe) override;
			virtual void onDestroyUniverse(Universe& universe) override;
			virtual void serialize(ISerializer& serializer) override;
			virtual void deserialize(ISerializer& serializer) override;
			virtual Component createComponent(uint32_t, const Entity&) override;
			virtual const char* getName() const override { return "animation"; }

			void destroy();
			Component createAnimable(const Entity& entity);
			void playAnimation(const Component& cmp, const char* path);
			void setAnimationTime(const Component& cmp, float time);
			Animation* loadAnimation(const char* path, FS::FileSystem& file_system);

		private:
			struct AnimationSystemImpl* m_impl;
	};


}// ~ namespace Lux 