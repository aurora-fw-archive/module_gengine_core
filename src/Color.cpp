#include <AuroraFW/GEngine/Color.h>

#include <AuroraFW/Math/Algorithm.h>

namespace AuroraFW {
	namespace GEngine {
		template<> BaseColor<float>::BaseColor(int r, int g, int b, int a)
			: r(Math::clamp(r, 0, 255)/255.0f), g(Math::clamp(g, 0, 255)/255.0f), b(Math::clamp(b, 0, 255)/255.0f), a(Math::clamp(a, 0, 255)/255.0f)
		{}

		template<> BaseColor<float>::BaseColor(uint32_t hex)
		{
			r = (byte)(hex >> 16)/255.0f;
			g = (byte)(hex >> 8)/255.0f;
			b = (byte)hex/255.0f;
		}

		template<> BaseColor<float>::BaseColor(CommonColor hex)
		{
			r = (byte)((uint32_t)hex >> 16)/255.0f;
			g = (byte)((uint32_t)hex >> 8)/255.0f;
			b = (byte)hex/255.0f;
		}

		template<> BaseColor<byte>::BaseColor(uint32_t hex)
		{
			r = (byte)(hex >> 16);
			g = (byte)(hex >> 8);
			b = (byte)hex;
		}

		template<> BaseColor<byte>::BaseColor(CommonColor hex)
		{
			r = (byte)((uint32_t)hex >> 16);
			g = (byte)((uint32_t)hex >> 8);
			b = (byte)hex;
		}
		
		template<> BaseColor<byte>::BaseColor(int r, int g, int b, int a)
			: r(r), g(g), b(b), a(a)
		{}

		template<> int BaseColor<float>::red() const
		{
			return r*255;
		}

		template<> int BaseColor<float>::green() const
		{
			return g*255;
		}

		template<> int BaseColor<float>::blue() const
		{
			return b*255;
		}

		template<> int BaseColor<float>::alpha() const
		{
			return a*255;
		}

		template<> float BaseColor<byte>::redF() const
		{
			return r/255.0f;
		}

		template<> float BaseColor<byte>::greenF() const
		{
			return g/255.0f;
		}

		template<> float BaseColor<byte>::blueF() const
		{
			return b/255.0f;
		}

		template<> float BaseColor<byte>::alphaF() const
		{
			return a/255.0f;
		}

		template<> void BaseColor<byte>::setRed(float _r)
		{
			r = _r*255;
		}

		template<> void BaseColor<byte>::setGreen(float _g)
		{
			g = _g*255;
		}

		template<> void BaseColor<byte>::setBlue(float _b)
		{
			b = _b*255;
		}
		
		template<> void BaseColor<byte>::setAlpha(float _a)
		{
			a = _a*255;
		}

		template<> void BaseColor<float>::setRed(int _r)
		{
			r = _r/255.0f;
		}

		template<> void BaseColor<float>::setGreen(int _g)
		{
			g = _g/255.0f;
		}

		template<> void BaseColor<float>::setBlue(int _b)
		{
			b = _b/255.0f;
		}
		
		template<> void BaseColor<float>::setAlpha(int _a)
		{
			a = _a/255.0f;
		}
	}
}