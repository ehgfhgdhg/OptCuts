
#ifndef IGL_STB_IMAGE_EXPORT_H
#define IGL_STB_IMAGE_EXPORT_H

#if defined(_MSC_VER)
// MSVC uses dllexport/dllimport
#ifdef BUILDING_DLL
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif
#define DLL_LOCAL
#elif defined(__GNUC__) || defined(__clang__)
// GCC/Clang uses visibility attribute
#define DLL_EXPORT __attribute__((visibility("default")))
#define DLL_LOCAL __attribute__((visibility("hidden")))
#else
#define DLL_EXPORT
#define DLL_LOCAL
#endif

#ifdef IGL_STB_IMAGE_STATIC_DEFINE
#  define IGL_STB_IMAGE_EXPORT
#  define IGL_STB_IMAGE_NO_EXPORT
#else
#  ifndef IGL_STB_IMAGE_EXPORT
#    ifdef igl_stb_image_EXPORTS
        /* We are building this library */
#      define IGL_STB_IMAGE_EXPORT DLL_EXPORT
#    else
        /* We are using this library */
#      define IGL_STB_IMAGE_EXPORT DLL_EXPORT
#    endif
#  endif

#  ifndef IGL_STB_IMAGE_NO_EXPORT
#    define IGL_STB_IMAGE_NO_EXPORT DLL_LOCAL
#  endif
#endif

#ifndef IGL_STB_IMAGE_DEPRECATED
#  define IGL_STB_IMAGE_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef IGL_STB_IMAGE_DEPRECATED_EXPORT
#  define IGL_STB_IMAGE_DEPRECATED_EXPORT IGL_STB_IMAGE_EXPORT IGL_STB_IMAGE_DEPRECATED
#endif

#ifndef IGL_STB_IMAGE_DEPRECATED_NO_EXPORT
#  define IGL_STB_IMAGE_DEPRECATED_NO_EXPORT IGL_STB_IMAGE_NO_EXPORT IGL_STB_IMAGE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef IGL_STB_IMAGE_NO_DEPRECATED
#    define IGL_STB_IMAGE_NO_DEPRECATED
#  endif
#endif

#endif /* IGL_STB_IMAGE_EXPORT_H */
