// --------------------------------------------------------------------------
// Class used to implement ASCII file reading and writing
// --------------------------------------------------------------------------

#ifndef _FILESYSTEM_H_
#define _FILESYSTEM_H_

// --------------------------------------------------------------------------
// File system
// --------------------------------------------------------------------------

class CFileSystem : virtual public CFileSystemPar,
		    virtual public CFileSystemString,
		    virtual public CFileSystemByte,
		    virtual public CFileSystemByteArray,
		    virtual public CFileSystemShort,
		    virtual public CFileSystemShortArray,
		    virtual public CFileSystemBoolean,
		    virtual public CFileSystemBooleanArray,
		    virtual public CFileSystemInteger,
		    virtual public CFileSystemIntegerArray,
		    virtual public CFileSystemLong,
		    virtual public CFileSystemLongArray,
		    virtual public CFileSystemFloat,
		    virtual public CFileSystemFloatArray,
		    virtual public CFileSystemDouble,
		    virtual public CFileSystemDoubleArray
{
// ----- Constructor and destructor -----------------------------------------
public:

CFileSystem() { };
~CFileSystem() { };
};

#endif	// _FILESYSTEM_H_
