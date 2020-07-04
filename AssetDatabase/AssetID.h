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
	struct AssetID
	{
	public:
		AssetID()
		{
			// TODO - this is probably a memory leak, but had issues with making it work with a static member
			GUID guid;
			GUID* gPtr = &guid;
			CoCreateGuid(gPtr);
			// TODO - probably a better way to do this copy all at once
			long* longPtr = (long*)gPtr;
			data1 = *longPtr;
			data2 = *(longPtr + 1);
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
		long data1;
		long data2;
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