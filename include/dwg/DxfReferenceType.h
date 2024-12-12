#ifndef DXF_REFERENCE_TYPE_H
#define DXF_REFERENCE_TYPE_H

namespace dwg {

enum DxfReferenceType : unsigned char {
    /// <summary>
    /// No reference, the value is a primitive
    /// </summary>
    None = 0,

    /// <summary>
    /// Handle reference, the value is a handle pointing to an object
    /// </summary>
    Handle = 1,

    /// <summary>
    /// Name reference, the value is a name pointing to an object
    /// </summary>
    Name = 2,

    /// <summary>
    /// Counter reference, the value is a list with multiple elements referenced
    /// to it
    /// </summary>
    Count = 4,

    /// <summary>
    /// Optional value
    /// </summary>
    Optional = 8,

    /// <summary>
    /// Value will be ignored by the reader and writer
    /// </summary>
    Ignored = 16,

    /// <summary>
    /// Value is an angle and must be converted when convinient
    /// </summary>
    IsAngle = 32,

    Unprocess = 64
};

} // namespace dwg

#endif /* DXF_REFERENCE_TYPE_H */