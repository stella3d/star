#pragma once
#include <cstddef>
#include <functional>
#include <combaseapi.h>
#include <guiddef.h>

namespace StarEditor
{
	/// <summary>
	/// Unique ID for an asset.  bit-for-bit identical to a GUID, but usable in hash maps more easily
	/// </summary>
	struct __declspec(dllexport) AssetID
	{
	public:
#pragma warning (suppress:26495)	// CoCreateGuid initializes both members
		AssetID()
		{
			CoCreateGuid((GUID*) &data1);
		}
		inline size_t GetHashCode() const
		{
			return data1 + 397 ^ data2;
		}

		inline bool operator ==(const AssetID& b) const
		{
			return this->data1 == b.data1 ? this->data2 == b.data2 : false;
		}

		static AssetID Create()
		{
			return *(new AssetID());
		}

	private:
		uint64_t data1;
		uint64_t data2;
	};
}

namespace std
{
	template <>
	struct hash<StarEditor::AssetID>
	{
		inline std::size_t operator()(const StarEditor::AssetID& c) const
		{
			return c.GetHashCode();
		}
	};
}