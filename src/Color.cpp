#include <AuroraFW/GEngine/Color.h>

#include <AuroraFW/Math/Algorithm.h>

namespace AuroraFW {
	namespace GEngine {
		template<> BaseColor<float>::BaseColor(int r, int g, int b, int a)
			: r(r/255.0f),
			  g(g/255.0f),
			  b(b/255.0f),
			  a(a/255.0f)
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
			r = hex >> 16;
			g = hex >> 8;
			b = hex;
		}

		template<> BaseColor<byte_t>::BaseColor(CommonColor hex)
		{
			r = (byte_t)((uint32_t)hex >> 16);
			g = (byte_t)((uint32_t)hex >> 8);
			b = (byte_t)hex;
		}
		
		template<> BaseColor<byte_t>::BaseColor(int r, int g, int b, int a)
			: r(r), g(g), b(b), a(a)
		{}

		template<> uint8_t BaseColor<float>::red() const
		{
			return r*255;
		}

		template<> uint8_t BaseColor<float>::green() const
		{
			return g*255;
		}

		template<> uint8_t BaseColor<float>::blue() const
		{
			return b*255;
		}

		template<> uint8_t BaseColor<float>::alpha() const
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

		template<> void BaseColor<float>::setRed(uint8_t _r)
		{
			r = _r/255.0f;
		}

		template<> void BaseColor<float>::setGreen(uint8_t _g)
		{
			g = _g/255.0f;
		}

		template<> void BaseColor<float>::setBlue(uint8_t _b)
		{
			b = _b/255.0f;
		}
		
		template<> void BaseColor<float>::setAlpha(uint8_t _a)
		{
			a = _a/255.0f;
		}
	}
}