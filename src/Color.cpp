#include <AuroraFW/GEngine/Color.h>

#include <AuroraFW/Math/Algorithm.h>

namespace AuroraFW {
	namespace GEngine {
		template<> BaseColor<float>::BaseColor(uint_t r, uint_t g, uint_t b, uint_t a)
			: r(Math::clamp(r, static_cast<uint_t>(0), static_cast<uint_t>(255))/255.0f),
			  g(Math::clamp(g, static_cast<uint_t>(0), static_cast<uint_t>(255))/255.0f),
			  b(Math::clamp(b, static_cast<uint_t>(0), static_cast<uint_t>(255))/255.0f),
			  a(Math::clamp(a, static_cast<uint_t>(0), static_cast<uint_t>(255))/255.0f)
		{}

		template<> BaseColor<float>::BaseColor(uint32_t hex)
		{
			r = (byte_t)(hex >> 16)/255.0f;
			g = (byte_t)(hex >> 8)/255.0f;
			b = (byte_t)hex/255.0f;
		}

		template<> BaseColor<float>::BaseColor(CommonColor hex)
		{
			r = (byte_t)((uint32_t)hex >> 16)/255.0f;
			g = (byte_t)((uint32_t)hex >> 8)/255.0f;
			b = (byte_t)hex/255.0f;
		}

		template<> BaseColor<byte_t>::BaseColor(uint32_t hex)
		{
			r = (byte_t)(hex >> 16);
			g = (byte_t)(hex >> 8);
			b = (byte_t)hex;
		}

		template<> BaseColor<byte_t>::BaseColor(CommonColor hex)
		{
			r = (byte_t)((uint32_t)hex >> 16);
			g = (byte_t)((uint32_t)hex >> 8);
			b = (byte_t)hex;
		}
		
		template<> BaseColor<byte_t>::BaseColor(uint_t r, uint_t g, uint_t b, uint_t a)
			: r(r), g(g), b(b), a(a)
		{}

		template<> uint_t BaseColor<float>::red() const
		{
			return r*255;
		}

		template<> uint_t BaseColor<float>::green() const
		{
			return g*255;
		}

		template<> uint_t BaseColor<float>::blue() const
		{
			return b*255;
		}

		template<> uint_t BaseColor<float>::alpha() const
		{
			return a*255;
		}

		template<> float BaseColor<byte_t>::redF() const
		{
			return r/255.0f;
		}

		template<> float BaseColor<byte_t>::greenF() const
		{
			return g/255.0f;
		}

		template<> float BaseColor<byte_t>::blueF() const
		{
			return b/255.0f;
		}

		template<> float BaseColor<byte_t>::alphaF() const
		{
			return a/255.0f;
		}

		template<> void BaseColor<byte_t>::setRed(float _r)
		{
			r = _r*255;
		}

		template<> void BaseColor<byte_t>::setGreen(float _g)
		{
			g = _g*255;
		}

		template<> void BaseColor<byte_t>::setBlue(float _b)
		{
			b = _b*255;
		}
		
		template<> void BaseColor<byte_t>::setAlpha(float _a)
		{
			a = _a*255;
		}

		template<> void BaseColor<float>::setRed(uint_t _r)
		{
			r = _r/255.0f;
		}

		template<> void BaseColor<float>::setGreen(uint_t _g)
		{
			g = _g/255.0f;
		}

		template<> void BaseColor<float>::setBlue(uint_t _b)
		{
			b = _b/255.0f;
		}
		
		template<> void BaseColor<float>::setAlpha(uint_t _a)
		{
			a = _a/255.0f;
		}
	}
}