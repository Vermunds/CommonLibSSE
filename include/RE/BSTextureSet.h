#pragma once

#include "RE/NiObject.h"  // NiObject


namespace RE
{
	class NiSourceTexture;


	class BSTextureSet : public NiObject
	{
	public:
		struct Textures
		{
			enum Texture : UInt32
			{
				kDiffuse = 0,
				kNormal,
				kGloss = kNormal,
				kEnvironmentMask,
				kSubsurfaceTint = kEnvironmentMask,
				kGlowMap,
				kDetailMap = kGlowMap,
				kHeight,
				kEnvironment,
				kMultilayer,
				kBacklightMask,
				kSpecular = kBacklightMask,
				kTotal
			};
		};

		using Texture = Textures::Texture;


		// override (NiObject)
		virtual NiRTTI*		GetRTTI() override;												// 02
		virtual void		LoadBinary(NiStream* a_stream) override;						// 18
		virtual void		LinkObject(NiStream* a_stream) override;						// 19
		virtual bool		RegisterStreamables(NiStream* a_stream) override;				// 1A
		virtual void		SaveBinary(NiStream* a_stream) override;						// 1B
		virtual bool		IsEqual(NiObject* a_object) override;							// 1C

		// add
		virtual const char*	GetTexturePath(Texture a_texture);								// 25
		virtual void		SetTexture(Texture a_texture, NiSourceTexture* a_srcTexture);	// 26
		virtual void		SetTexturePath(Texture a_texture, const char* a_path);			// 27
	};
	STATIC_ASSERT(sizeof(BSTextureSet) == 0x10);
}
