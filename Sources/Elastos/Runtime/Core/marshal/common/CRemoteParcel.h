
#ifndef __CREMOTEPARCEL_H__
#define __CREMOTEPARCEL_H__

#include <elastos.h>
#include "marshal.h"

class CParcelSession;

class CRemoteParcel : public IParcel
{
public:
    CRemoteParcel(
        /* [in] */ CParcelSession* pParcelSession);

    CRemoteParcel(
        /* [in] */ CParcelSession* pParcelSession,
        /* [in] */ UInt32 *elemBuf);

    virtual ~CRemoteParcel();

    CARAPI_(UInt32)AddRef();

    CARAPI_(UInt32)Release();

    CARAPI_(PInterface) Probe(
        /* [in] */ REIID riid);

    CARAPI GetInterfaceID(
        /* [in] */ IInterface *pObject,
        /* [out] */ InterfaceID *pIID);

    CARAPI Marshall(
        /* [out, callee] */ ArrayOf<Byte>** bytes);

    CARAPI Unmarshall(
        /* [in] */ ArrayOf<Byte>* data,
        /* [in] */ Int32 offset,
        /* [in] */ Int32 length);

    CARAPI AppendFrom(
        /* [in] */ IParcel* parcel,
        /* [in] */ Int32 offset,
        /* [in] */ Int32 length);

    CARAPI HasFileDescriptors(
        /* [out] */ Boolean* result);

    CARAPI ReadByte(
        /* [out] */ Byte *pValue);

    CARAPI WriteByte(
        /* [in] */ Byte value);

    CARAPI ReadBoolean(
        /* [out] */ Boolean *pValue);

    CARAPI WriteBoolean(
        /* [in] */ Boolean value);

    CARAPI ReadChar(
        /* [out] */ Char32 *pValue);

    CARAPI WriteChar(
        /* [in] */ Char32 value);

    CARAPI ReadInt16(
        /* [out] */ Int16 *pValue);

    CARAPI WriteInt16(
        /* [in] */ Int16 value);

    CARAPI ReadInt32(
        /* [out] */ Int32 *pValue);

    CARAPI WriteInt32(
        /* [in] */ Int32 value);

    CARAPI ReadInt64(
        /* [out] */ Int64 *pValue);

    CARAPI WriteInt64(
        /* [in] */ Int64 value);

    CARAPI ReadFloat(
        /* [out] */ Float *value);

    CARAPI WriteFloat(
        /* [in] */ Float value);

    CARAPI ReadDouble(
        /* [out] */ Double *value);

    CARAPI WriteDouble(
        /* [in] */ Double value);

    CARAPI ReadString(
        /* [out] */ String* pStr);

    CARAPI WriteString(
        /* [in] */ const String& str);

    CARAPI ReadStruct(
        /* [out] */ PVoid *pAddress);

    CARAPI WriteStruct(
        /* [in] */ PVoid pValue,
        /* [in] */ Int32 size);

    CARAPI ReadEMuid(
        /* [out] */ EMuid *pId);

    CARAPI WriteEMuid(
        /* [in] */ const EMuid & id);

    CARAPI ReadEGuid(
        /* [out] */ EGuid *pId);

    CARAPI WriteEGuid(
        /* [in] */ const EGuid & id);

    CARAPI ReadArrayOf(
        /* [out] */ PVoid *ppArray);

    CARAPI WriteArrayOf(
        /* [in] */ PVoid pArray);

    CARAPI ReadArrayOfString(
        /* [out, callee] */ ArrayOf<String>** ppArray);

    CARAPI WriteArrayOfString(
        /* [in] */ ArrayOf<String>* array);

    CARAPI ReadInterfacePtr(
        /* [out] */ IInterface **pItfPtr);

    CARAPI WriteInterfacePtr(
        /* [in] */ IInterface* pValue);

    // Place a file descriptor into the parcel.  The given fd must remain
    // valid for the lifetime of the parcel.
    CARAPI WriteFileDescriptor(
        /* [in] */ Int32 fd);

    // Place a file descriptor into the parcel.  A dup of the fd is made, which
    // will be closed once the parcel is destroyed.
    CARAPI WriteDupFileDescriptor(
        /* [in] */ Int32 fd);

    // Retrieve a file descriptor from the parcel.  This returns the raw fd
    // in the parcel, which you do not own -- use dup() to get your own copy.
    CARAPI ReadFileDescriptor(
        /* [out] */ Int32* fd);

    CARAPI Clone(
        /* [in] */ IParcel* pSrcParcel);

    CARAPI GetDataPosition(
        /* [out] */ Int32* position);

    CARAPI SetDataPosition(
        /* [in] */ Int32 position);

    CARAPI GetElementSize(
        /* [out] */ Int32* pSize);

    CARAPI GetElementPayload(
        /* [ouy] */ PVoid* pBuffer);

    CARAPI GetDataSize(
        /* [out] */ Int32* size);

    CARAPI SetDataSize(
        /* [in] */ Int32 size);

    CARAPI GetDataCapacity(
        /* [out] */ Int32* capacity);

    CARAPI SetDataCapacity(
        /* [in] */ Int32 capacity);

    CARAPI GetDataPayload(
        /* [ouy] */ Handle32* buffer);

public:
    CARAPI_(MarshalHeader*) GetMarshalHeader();

private:
    CARAPI GrowElemBuffer(
        /* [in] */ Int32 minSize);

    CARAPI ReadValue(PVoid pValue, Int32 type);

    CARAPI WriteValue(PVoid pValue, Int32 type, Int32 size);

    CARAPI_(Boolean) IsParcelable(
        /* [in] */ InterfacePack *pInterfacePack,
        /* [out] */ CIClassInfo **ppClassInfo);

private:
    Int32 m_nRefs;

    UInt32* m_elemBuf;
    UInt32* m_elemPtr;
    Int32 m_elemBufCapacity;

    Boolean m_freeDataTag;

    CParcelSession* mParcelSession;
};

#endif //__CREMOTEPARCEL_H__
