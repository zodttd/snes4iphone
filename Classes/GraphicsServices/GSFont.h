#ifndef GRAPHICSSERVICES_GSFONT_H_
#define GRAPHICSSERVICES_GSFONT_H_

#ifdef __cplusplus
extern "C" {
#endif

enum {
    kGSFontItalicTrait    = (1 <<  0),
    kGSFontBoldTrait      = (1 <<  1),
    kGSFontExpandedTrait  = (1 <<  5),
    kGSFontCondensedTrait = (1 <<  6),
    kGSFontMonoSpaceTrait = (1 << 10),
    kGSFontVerticalTrait  = (1 << 11),
}; typedef uint32_t GSFontSymbolicTraits;

typedef struct __GSFont *GSFontRef;

GSFontRef GSFontCreateWithName(const char *name, GSFontSymbolicTraits traits, float size);

#ifdef __cplusplus
}
#endif

#endif/*GRAPHICSSERVICES_GSFONT_H_*/
