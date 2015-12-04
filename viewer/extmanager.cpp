// --------------------------------------------------------------------------
// Source file for the extension manager
//
// Stored in file extmanager.cpp
//
// File:   extmanager.cpp
// Author: Automatic code generator
// Date:   Fri Dec  4 06:40:02 2015
// System: galacticcore
// User:   msar
// Script: extcode.txt
// Config: config.txt
// Path:   /home/msar/Desktop/PROJECTS/NEXTGEN/openglextensionviewer/viewer
//
// From: extcode.h (Internal version)
// --------------------------------------------------------------------------
//
// This file is based on the following header files:
//
// Set   1
// registry/wglext.h - Version unknown
// registry/glext.h  - Version 20151120
// registry/glxext.h - Version 20150623
//
// --------------------------------------------------------------------------
//
// The following extensions are currently supported by this class:
//
// ----- 557 GL extensions ---------
//
//  12 GL_AMD_multi_draw_indirect
//  19 GL_AMD_seamless_cubemap_per_texture
//  28 GL_AMD_vertex_shader_layer
//  30 GL_AMD_vertex_shader_viewport_index
//  47 GL_ARB_ES2_compatibility
//  48 GL_ARB_ES3_1_compatibility
//  50 GL_ARB_ES3_compatibility
//  51 GL_ARB_arrays_of_arrays
//  52 GL_ARB_base_instance
//  53 GL_ARB_bindless_texture
//  54 GL_ARB_blend_func_extended
//  55 GL_ARB_buffer_storage
//  57 GL_ARB_clear_buffer_object
//  58 GL_ARB_clear_texture
//  59 GL_ARB_clip_control
//  60 GL_ARB_color_buffer_float
//  61 GL_ARB_compatibility
//  62 GL_ARB_compressed_texture_pixel_storage
//  63 GL_ARB_compute_shader
//  64 GL_ARB_compute_variable_group_size
//  65 GL_ARB_conditional_render_inverted
//  66 GL_ARB_conservative_depth
//  67 GL_ARB_copy_buffer
//  68 GL_ARB_copy_image
//  69 GL_ARB_cull_distance
//  70 GL_ARB_debug_output
//  71 GL_ARB_depth_buffer_float
//  72 GL_ARB_depth_clamp
//  73 GL_ARB_depth_texture
//  74 GL_ARB_derivative_control
//  75 GL_ARB_direct_state_access
//  76 GL_ARB_draw_buffers
//  77 GL_ARB_draw_buffers_blend
//  78 GL_ARB_draw_elements_base_vertex
//  79 GL_ARB_draw_indirect
//  80 GL_ARB_draw_instanced
//  81 GL_ARB_enhanced_layouts
//  82 GL_ARB_explicit_attrib_location
//  83 GL_ARB_explicit_uniform_location
//  84 GL_ARB_fragment_coord_conventions
//  85 GL_ARB_fragment_layer_viewport
//  86 GL_ARB_fragment_program
//  87 GL_ARB_fragment_program_shadow
//  88 GL_ARB_fragment_shader
//  90 GL_ARB_framebuffer_no_attachments
//  91 GL_ARB_framebuffer_object
//  92 GL_ARB_framebuffer_sRGB
//  93 GL_ARB_geometry_shader4
//  94 GL_ARB_get_program_binary
//  95 GL_ARB_get_texture_sub_image
//  96 GL_ARB_gpu_shader5
//  97 GL_ARB_gpu_shader_fp64
//  99 GL_ARB_half_float_pixel
// 100 GL_ARB_half_float_vertex
// 101 GL_ARB_imaging
// 102 GL_ARB_indirect_parameters
// 103 GL_ARB_instanced_arrays
// 104 GL_ARB_internalformat_query
// 105 GL_ARB_internalformat_query2
// 106 GL_ARB_invalidate_subdata
// 107 GL_ARB_map_buffer_alignment
// 108 GL_ARB_map_buffer_range
// 110 GL_ARB_multi_bind
// 111 GL_ARB_multi_draw_indirect
// 112 GL_ARB_multisample
// 113 GL_ARB_multitexture
// 114 GL_ARB_occlusion_query
// 115 GL_ARB_occlusion_query2
// 117 GL_ARB_pipeline_statistics_query
// 118 GL_ARB_pixel_buffer_object
// 119 GL_ARB_point_parameters
// 120 GL_ARB_point_sprite
// 122 GL_ARB_program_interface_query
// 123 GL_ARB_provoking_vertex
// 124 GL_ARB_query_buffer_object
// 125 GL_ARB_robust_buffer_access_behavior
// 126 GL_ARB_robustness
// 129 GL_ARB_sample_shading
// 130 GL_ARB_sampler_objects
// 131 GL_ARB_seamless_cube_map
// 132 GL_ARB_seamless_cubemap_per_texture
// 133 GL_ARB_separate_shader_objects
// 135 GL_ARB_shader_atomic_counters
// 137 GL_ARB_shader_bit_encoding
// 139 GL_ARB_shader_draw_parameters
// 140 GL_ARB_shader_group_vote
// 141 GL_ARB_shader_image_load_store
// 142 GL_ARB_shader_image_size
// 143 GL_ARB_shader_objects
// 144 GL_ARB_shader_precision
// 146 GL_ARB_shader_storage_buffer_object
// 147 GL_ARB_shader_subroutine
// 148 GL_ARB_shader_texture_image_samples
// 149 GL_ARB_shader_texture_lod
// 151 GL_ARB_shading_language_100
// 152 GL_ARB_shading_language_420pack
// 153 GL_ARB_shading_language_include
// 154 GL_ARB_shading_language_packing
// 155 GL_ARB_shadow
// 157 GL_ARB_sparse_buffer
// 158 GL_ARB_sparse_texture
// 161 GL_ARB_stencil_texturing
// 162 GL_ARB_sync
// 163 GL_ARB_tessellation_shader
// 164 GL_ARB_texture_barrier
// 165 GL_ARB_texture_border_clamp
// 166 GL_ARB_texture_buffer_object
// 167 GL_ARB_texture_buffer_object_rgb32
// 168 GL_ARB_texture_buffer_range
// 169 GL_ARB_texture_compression
// 170 GL_ARB_texture_compression_bptc
// 171 GL_ARB_texture_compression_rgtc
// 172 GL_ARB_texture_cube_map
// 173 GL_ARB_texture_cube_map_array
// 174 GL_ARB_texture_env_add
// 175 GL_ARB_texture_env_combine
// 176 GL_ARB_texture_env_crossbar
// 177 GL_ARB_texture_env_dot3
// 179 GL_ARB_texture_float
// 180 GL_ARB_texture_gather
// 181 GL_ARB_texture_mirror_clamp_to_edge
// 182 GL_ARB_texture_mirrored_repeat
// 183 GL_ARB_texture_multisample
// 184 GL_ARB_texture_non_power_of_two
// 185 GL_ARB_texture_query_levels
// 186 GL_ARB_texture_query_lod
// 187 GL_ARB_texture_rectangle
// 188 GL_ARB_texture_rg
// 189 GL_ARB_texture_rgb10_a2ui
// 190 GL_ARB_texture_stencil8
// 191 GL_ARB_texture_storage
// 192 GL_ARB_texture_storage_multisample
// 193 GL_ARB_texture_swizzle
// 194 GL_ARB_texture_view
// 195 GL_ARB_timer_query
// 196 GL_ARB_transform_feedback2
// 197 GL_ARB_transform_feedback3
// 198 GL_ARB_transform_feedback_instanced
// 199 GL_ARB_transform_feedback_overflow_query
// 200 GL_ARB_transpose_matrix
// 201 GL_ARB_uniform_buffer_object
// 202 GL_ARB_vertex_array_bgra
// 203 GL_ARB_vertex_array_object
// 204 GL_ARB_vertex_attrib_64bit
// 205 GL_ARB_vertex_attrib_binding
// 207 GL_ARB_vertex_buffer_object
// 208 GL_ARB_vertex_program
// 209 GL_ARB_vertex_shader
// 210 GL_ARB_vertex_type_10f_11f_11f_rev
// 211 GL_ARB_vertex_type_2_10_10_10_rev
// 212 GL_ARB_viewport_array
// 213 GL_ARB_window_pos
// 214 GL_ATI_draw_buffers
// 225 GL_ATI_texture_float
// 226 GL_ATI_texture_mirror_once
// 231 GL_EXT_abgr
// 232 GL_EXT_bgra
// 233 GL_EXT_bindable_uniform
// 234 GL_EXT_blend_color
// 235 GL_EXT_blend_equation_separate
// 236 GL_EXT_blend_func_separate
// 238 GL_EXT_blend_minmax
// 239 GL_EXT_blend_subtract
// 243 GL_EXT_compiled_vertex_array
// 250 GL_EXT_depth_bounds_test
// 251 GL_EXT_direct_state_access
// 252 GL_EXT_draw_buffers2
// 253 GL_EXT_draw_instanced
// 254 GL_EXT_draw_range_elements
// 255 GL_EXT_fog_coord
// 256 GL_EXT_framebuffer_blit
// 257 GL_EXT_framebuffer_multisample
// 258 GL_EXT_framebuffer_multisample_blit_scaled
// 259 GL_EXT_framebuffer_object
// 260 GL_EXT_framebuffer_sRGB
// 261 GL_EXT_geometry_shader4
// 262 GL_EXT_gpu_program_parameters
// 263 GL_EXT_gpu_shader4
// 271 GL_EXT_multi_draw_arrays
// 273 GL_EXT_packed_depth_stencil
// 274 GL_EXT_packed_float
// 275 GL_EXT_packed_pixels
// 277 GL_EXT_pixel_buffer_object
// 280 GL_EXT_point_parameters
// 282 GL_EXT_polygon_offset_clamp
// 283 GL_EXT_post_depth_coverage
// 284 GL_EXT_provoking_vertex
// 285 GL_EXT_raster_multisample
// 286 GL_EXT_rescale_normal
// 287 GL_EXT_secondary_color
// 288 GL_EXT_separate_shader_objects
// 289 GL_EXT_separate_specular_color
// 290 GL_EXT_shader_image_load_formatted
// 291 GL_EXT_shader_image_load_store
// 292 GL_EXT_shader_integer_mix
// 293 GL_EXT_shadow_funcs
// 295 GL_EXT_sparse_texture2
// 297 GL_EXT_stencil_two_side
// 298 GL_EXT_stencil_wrap
// 301 GL_EXT_texture3D
// 302 GL_EXT_texture_array
// 303 GL_EXT_texture_buffer_object
// 304 GL_EXT_texture_compression_latc
// 305 GL_EXT_texture_compression_rgtc
// 306 GL_EXT_texture_compression_s3tc
// 307 GL_EXT_texture_cube_map
// 308 GL_EXT_texture_env_add
// 309 GL_EXT_texture_env_combine
// 310 GL_EXT_texture_env_dot3
// 311 GL_EXT_texture_filter_anisotropic
// 312 GL_EXT_texture_filter_minmax
// 313 GL_EXT_texture_integer
// 314 GL_EXT_texture_lod_bias
// 315 GL_EXT_texture_mirror_clamp
// 316 GL_EXT_texture_object
// 318 GL_EXT_texture_sRGB
// 319 GL_EXT_texture_sRGB_decode
// 320 GL_EXT_texture_shared_exponent
// 322 GL_EXT_texture_swizzle
// 323 GL_EXT_timer_query
// 325 GL_EXT_vertex_array
// 326 GL_EXT_vertex_array_bgra
// 327 GL_EXT_vertex_attrib_64bit
// 330 GL_EXT_x11_sync_object
// 339 GL_IBM_rasterpos_clip
// 341 GL_IBM_texture_mirrored_repeat
// 351 GL_KHR_blend_equation_advanced
// 352 GL_KHR_blend_equation_advanced_coherent
// 353 GL_KHR_context_flush_control
// 354 GL_KHR_debug
// 356 GL_KHR_robust_buffer_access_behavior
// 357 GL_KHR_robustness
// 366 GL_NVX_conditional_render
// 367 GL_NVX_gpu_memory_info
// 368 GL_NV_bindless_multi_draw_indirect
// 369 GL_NV_bindless_multi_draw_indirect_count
// 370 GL_NV_bindless_texture
// 371 GL_NV_blend_equation_advanced
// 372 GL_NV_blend_equation_advanced_coherent
// 373 GL_NV_blend_square
// 374 GL_NV_command_list
// 375 GL_NV_compute_program5
// 376 GL_NV_conditional_render
// 377 GL_NV_conservative_raster
// 378 GL_NV_conservative_raster_dilate
// 379 GL_NV_copy_depth_to_color
// 380 GL_NV_copy_image
// 382 GL_NV_depth_buffer_float
// 383 GL_NV_depth_clamp
// 384 GL_NV_draw_texture
// 386 GL_NV_explicit_multisample
// 387 GL_NV_fence
// 388 GL_NV_fill_rectangle
// 389 GL_NV_float_buffer
// 390 GL_NV_fog_distance
// 391 GL_NV_fragment_coverage_to_color
// 392 GL_NV_fragment_program
// 393 GL_NV_fragment_program2
// 395 GL_NV_fragment_program_option
// 396 GL_NV_fragment_shader_interlock
// 397 GL_NV_framebuffer_mixed_samples
// 398 GL_NV_framebuffer_multisample_coverage
// 400 GL_NV_geometry_shader4
// 401 GL_NV_geometry_shader_passthrough
// 402 GL_NV_gpu_program4
// 403 GL_NV_gpu_program5
// 404 GL_NV_gpu_program5_mem_extended
// 405 GL_NV_gpu_shader5
// 406 GL_NV_half_float
// 407 GL_NV_internalformat_sample_query
// 408 GL_NV_light_max_exponent
// 409 GL_NV_multisample_coverage
// 410 GL_NV_multisample_filter_hint
// 411 GL_NV_occlusion_query
// 412 GL_NV_packed_depth_stencil
// 413 GL_NV_parameter_buffer_object
// 414 GL_NV_parameter_buffer_object2
// 415 GL_NV_path_rendering
// 416 GL_NV_path_rendering_shared_edge
// 417 GL_NV_pixel_data_range
// 418 GL_NV_point_sprite
// 420 GL_NV_primitive_restart
// 421 GL_NV_register_combiners
// 422 GL_NV_register_combiners2
// 423 GL_NV_sample_locations
// 424 GL_NV_sample_mask_override_coverage
// 425 GL_NV_shader_atomic_counters
// 426 GL_NV_shader_atomic_float
// 427 GL_NV_shader_atomic_fp16_vector
// 428 GL_NV_shader_atomic_int64
// 429 GL_NV_shader_buffer_load
// 431 GL_NV_shader_storage_buffer_object
// 432 GL_NV_shader_thread_group
// 433 GL_NV_shader_thread_shuffle
// 436 GL_NV_texgen_reflection
// 437 GL_NV_texture_barrier
// 438 GL_NV_texture_compression_vtc
// 439 GL_NV_texture_env_combine4
// 441 GL_NV_texture_multisample
// 442 GL_NV_texture_rectangle
// 443 GL_NV_texture_shader
// 444 GL_NV_texture_shader2
// 445 GL_NV_texture_shader3
// 446 GL_NV_transform_feedback
// 447 GL_NV_transform_feedback2
// 448 GL_NV_uniform_buffer_unified_memory
// 449 GL_NV_vdpau_interop
// 450 GL_NV_vertex_array_range
// 451 GL_NV_vertex_array_range2
// 452 GL_NV_vertex_attrib_integer_64bit
// 453 GL_NV_vertex_buffer_unified_memory
// 454 GL_NV_vertex_program
// 455 GL_NV_vertex_program1_1
// 456 GL_NV_vertex_program2
// 457 GL_NV_vertex_program2_option
// 458 GL_NV_vertex_program3
// 461 GL_NV_viewport_array2
// 476 GL_S3_s3tc
// 479 GL_SGIS_generate_mipmap
// 490 GL_SGIS_texture_lod
// 500 GL_SGIX_depth_texture
// 516 GL_SGIX_shadow
// 537 GL_SUN_slice_accum
//
// -----   0 GLX extensions ----------
//
//   3 GLX_ARB_context_flush_control
//   4 GLX_ARB_create_context
//   5 GLX_ARB_create_context_profile
//   6 GLX_ARB_create_context_robustness
//   7 GLX_ARB_fbconfig_float
//  10 GLX_ARB_multisample
//  14 GLX_EXT_buffer_age
//  15 GLX_EXT_create_context_es2_profile
//  16 GLX_EXT_create_context_es_profile
//  17 GLX_EXT_fbconfig_packed_float
//  18 GLX_EXT_framebuffer_sRGB
//  19 GLX_EXT_import_context
//  20 GLX_EXT_stereo_tree
//  21 GLX_EXT_swap_control
//  22 GLX_EXT_swap_control_tear
//  23 GLX_EXT_texture_from_pixmap
//  24 GLX_EXT_visual_info
//  25 GLX_EXT_visual_rating
//  33 GLX_NV_copy_buffer
//  34 GLX_NV_copy_image
//  35 GLX_NV_delay_before_swap
//  36 GLX_NV_float_buffer
//  37 GLX_NV_multisample_coverage
//  38 GLX_NV_present_video
//  39 GLX_NV_swap_group
//  40 GLX_NV_video_capture
//  41 GLX_NV_video_out
//  48 GLX_SGIX_fbconfig
//  50 GLX_SGIX_pbuffer
//  58 GLX_SGI_swap_control
//  59 GLX_SGI_video_sync
// --------------------------------------------------------------------------


#ifdef _WIN32
//#include "stdafx.h"
#endif

#include <stdio.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glext.h>
#ifdef _WIN32
#include <GL/wglext.h>
#endif

#define _GLX

#ifdef  _GLX
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <GL/glx.h>
#include <GL/glxext.h>
#endif

#include "extmanager.h"

// ----- GL extensions -------

#ifdef GL_AMD_multi_draw_indirect
PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC	glMultiDrawArraysIndirectAMD = NULL;
PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC	glMultiDrawElementsIndirectAMD = NULL;
#endif		// GL_AMD_multi_draw_indirect

#ifdef GL_ARB_draw_buffers_blend
PFNGLBLENDEQUATIONIARBPROC	glBlendEquationiARB = NULL;
PFNGLBLENDEQUATIONSEPARATEIARBPROC	glBlendEquationSeparateiARB = NULL;
PFNGLBLENDFUNCIARBPROC	glBlendFunciARB = NULL;
PFNGLBLENDFUNCSEPARATEIARBPROC	glBlendFuncSeparateiARB = NULL;
#endif		// GL_ARB_draw_buffers_blend

#ifdef GL_ARB_draw_instanced
PFNGLDRAWARRAYSINSTANCEDARBPROC	glDrawArraysInstancedARB = NULL;
PFNGLDRAWELEMENTSINSTANCEDARBPROC	glDrawElementsInstancedARB = NULL;
#endif		// GL_ARB_draw_instanced

#ifdef GL_ARB_window_pos
PFNGLWINDOWPOS2DARBPROC	glWindowPos2dARB = NULL;
PFNGLWINDOWPOS2DVARBPROC	glWindowPos2dvARB = NULL;
PFNGLWINDOWPOS2FARBPROC	glWindowPos2fARB = NULL;
PFNGLWINDOWPOS2FVARBPROC	glWindowPos2fvARB = NULL;
PFNGLWINDOWPOS2IARBPROC	glWindowPos2iARB = NULL;
PFNGLWINDOWPOS2IVARBPROC	glWindowPos2ivARB = NULL;
PFNGLWINDOWPOS2SARBPROC	glWindowPos2sARB = NULL;
PFNGLWINDOWPOS2SVARBPROC	glWindowPos2svARB = NULL;
PFNGLWINDOWPOS3DARBPROC	glWindowPos3dARB = NULL;
PFNGLWINDOWPOS3DVARBPROC	glWindowPos3dvARB = NULL;
PFNGLWINDOWPOS3FARBPROC	glWindowPos3fARB = NULL;
PFNGLWINDOWPOS3FVARBPROC	glWindowPos3fvARB = NULL;
PFNGLWINDOWPOS3IARBPROC	glWindowPos3iARB = NULL;
PFNGLWINDOWPOS3IVARBPROC	glWindowPos3ivARB = NULL;
PFNGLWINDOWPOS3SARBPROC	glWindowPos3sARB = NULL;
PFNGLWINDOWPOS3SVARBPROC	glWindowPos3svARB = NULL;
#endif		// GL_ARB_window_pos

#ifdef GL_EXT_draw_buffers2
PFNGLCOLORMASKINDEXEDEXTPROC	glColorMaskIndexedEXT = NULL;
#endif		// GL_EXT_draw_buffers2

#ifdef GL_EXT_draw_instanced
PFNGLDRAWARRAYSINSTANCEDEXTPROC	glDrawArraysInstancedEXT = NULL;
PFNGLDRAWELEMENTSINSTANCEDEXTPROC	glDrawElementsInstancedEXT = NULL;
#endif		// GL_EXT_draw_instanced

#ifdef GL_EXT_gpu_program_parameters
PFNGLPROGRAMENVPARAMETERS4FVEXTPROC	glProgramEnvParameters4fvEXT = NULL;
PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC	glProgramLocalParameters4fvEXT = NULL;
#endif		// GL_EXT_gpu_program_parameters

#ifdef GL_EXT_multi_draw_arrays
PFNGLMULTIDRAWARRAYSEXTPROC	glMultiDrawArraysEXT = NULL;
PFNGLMULTIDRAWELEMENTSEXTPROC	glMultiDrawElementsEXT = NULL;
#endif		// GL_EXT_multi_draw_arrays

#ifdef GL_NVX_conditional_render
PFNGLBEGINCONDITIONALRENDERNVXPROC	glBeginConditionalRenderNVX = NULL;
PFNGLENDCONDITIONALRENDERNVXPROC	glEndConditionalRenderNVX = NULL;
#endif		// GL_NVX_conditional_render

#ifdef GL_NV_bindless_multi_draw_indirect
PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC	glMultiDrawArraysIndirectBindlessNV = NULL;
PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC	glMultiDrawElementsIndirectBindlessNV = NULL;
#endif		// GL_NV_bindless_multi_draw_indirect

#ifdef GL_NV_bindless_multi_draw_indirect_count
PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC	glMultiDrawArraysIndirectBindlessCountNV = NULL;
PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC	glMultiDrawElementsIndirectBindlessCountNV = NULL;
#endif		// GL_NV_bindless_multi_draw_indirect_count

#ifdef GL_NV_bindless_texture
PFNGLGETTEXTUREHANDLENVPROC	glGetTextureHandleNV = NULL;
PFNGLGETTEXTURESAMPLERHANDLENVPROC	glGetTextureSamplerHandleNV = NULL;
PFNGLMAKETEXTUREHANDLERESIDENTNVPROC	glMakeTextureHandleResidentNV = NULL;
PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC	glMakeTextureHandleNonResidentNV = NULL;
PFNGLGETIMAGEHANDLENVPROC	glGetImageHandleNV = NULL;
PFNGLMAKEIMAGEHANDLERESIDENTNVPROC	glMakeImageHandleResidentNV = NULL;
PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC	glMakeImageHandleNonResidentNV = NULL;
PFNGLUNIFORMHANDLEUI64NVPROC	glUniformHandleui64NV = NULL;
PFNGLUNIFORMHANDLEUI64VNVPROC	glUniformHandleui64vNV = NULL;
PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC	glProgramUniformHandleui64NV = NULL;
PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC	glProgramUniformHandleui64vNV = NULL;
PFNGLISTEXTUREHANDLERESIDENTNVPROC	glIsTextureHandleResidentNV = NULL;
PFNGLISIMAGEHANDLERESIDENTNVPROC	glIsImageHandleResidentNV = NULL;
#endif		// GL_NV_bindless_texture

#ifdef GL_NV_copy_image
PFNGLCOPYIMAGESUBDATANVPROC	glCopyImageSubDataNV = NULL;
#endif		// GL_NV_copy_image

#ifdef GL_NV_draw_texture
PFNGLDRAWTEXTURENVPROC	glDrawTextureNV = NULL;
#endif		// GL_NV_draw_texture

#ifdef GL_NV_texture_barrier
PFNGLTEXTUREBARRIERNVPROC	glTextureBarrierNV = NULL;
#endif		// GL_NV_texture_barrier

#ifdef GL_NV_vertex_attrib_integer_64bit
PFNGLVERTEXATTRIBL1I64NVPROC	glVertexAttribL1i64NV = NULL;
PFNGLVERTEXATTRIBL2I64NVPROC	glVertexAttribL2i64NV = NULL;
PFNGLVERTEXATTRIBL3I64NVPROC	glVertexAttribL3i64NV = NULL;
PFNGLVERTEXATTRIBL4I64NVPROC	glVertexAttribL4i64NV = NULL;
PFNGLVERTEXATTRIBL1I64VNVPROC	glVertexAttribL1i64vNV = NULL;
PFNGLVERTEXATTRIBL2I64VNVPROC	glVertexAttribL2i64vNV = NULL;
PFNGLVERTEXATTRIBL3I64VNVPROC	glVertexAttribL3i64vNV = NULL;
PFNGLVERTEXATTRIBL4I64VNVPROC	glVertexAttribL4i64vNV = NULL;
PFNGLVERTEXATTRIBL1UI64NVPROC	glVertexAttribL1ui64NV = NULL;
PFNGLVERTEXATTRIBL2UI64NVPROC	glVertexAttribL2ui64NV = NULL;
PFNGLVERTEXATTRIBL3UI64NVPROC	glVertexAttribL3ui64NV = NULL;
PFNGLVERTEXATTRIBL4UI64NVPROC	glVertexAttribL4ui64NV = NULL;
PFNGLVERTEXATTRIBL1UI64VNVPROC	glVertexAttribL1ui64vNV = NULL;
PFNGLVERTEXATTRIBL2UI64VNVPROC	glVertexAttribL2ui64vNV = NULL;
PFNGLVERTEXATTRIBL3UI64VNVPROC	glVertexAttribL3ui64vNV = NULL;
PFNGLVERTEXATTRIBL4UI64VNVPROC	glVertexAttribL4ui64vNV = NULL;
PFNGLGETVERTEXATTRIBLI64VNVPROC	glGetVertexAttribLi64vNV = NULL;
PFNGLGETVERTEXATTRIBLUI64VNVPROC	glGetVertexAttribLui64vNV = NULL;
PFNGLVERTEXATTRIBLFORMATNVPROC	glVertexAttribLFormatNV = NULL;
#endif		// GL_NV_vertex_attrib_integer_64bit


// ----- GLX extensions --------

#ifdef _GLX

#ifdef GLX_NV_copy_buffer
PFNGLXCOPYBUFFERSUBDATANVPROC	glXCopyBufferSubDataNV = NULL;
PFNGLXNAMEDCOPYBUFFERSUBDATANVPROC	glXNamedCopyBufferSubDataNV = NULL;
#endif		// GLX_NV_copy_buffer

#ifdef GLX_NV_copy_image
PFNGLXCOPYIMAGESUBDATANVPROC	glXCopyImageSubDataNV = NULL;
#endif		// GLX_NV_copy_image

#ifdef GLX_NV_delay_before_swap
PFNGLXDELAYBEFORESWAPNVPROC	glXDelayBeforeSwapNV = NULL;
#endif		// GLX_NV_delay_before_swap

#ifdef GLX_NV_swap_group
PFNGLXJOINSWAPGROUPNVPROC	glXJoinSwapGroupNV = NULL;
PFNGLXBINDSWAPBARRIERNVPROC	glXBindSwapBarrierNV = NULL;
PFNGLXQUERYSWAPGROUPNVPROC	glXQuerySwapGroupNV = NULL;
PFNGLXQUERYMAXSWAPGROUPSNVPROC	glXQueryMaxSwapGroupsNV = NULL;
PFNGLXQUERYFRAMECOUNTNVPROC	glXQueryFrameCountNV = NULL;
PFNGLXRESETFRAMECOUNTNVPROC	glXResetFrameCountNV = NULL;
#endif		// GLX_NV_swap_group

#ifdef GLX_SGI_swap_control
PFNGLXSWAPINTERVALSGIPROC	glXSwapIntervalSGI = NULL;
#endif		// GLX_SGI_swap_control

#ifdef GLX_SGI_video_sync
PFNGLXGETVIDEOSYNCSGIPROC	glXGetVideoSyncSGI = NULL;
PFNGLXWAITVIDEOSYNCSGIPROC	glXWaitVideoSyncSGI = NULL;
#endif		// GLX_SGI_video_sync

#endif		// _GLX

// Extension presence flags

int m_OpenGL12 = 0;
int m_OpenGL13 = 0;
int m_OpenGL14 = 0;
int m_OpenGL15 = 0;
int m_OpenGL20 = 0;
int m_OpenGL21 = 0;
int m_OpenGL30 = 0;
int m_OpenGL31 = 0;
int m_OpenGL32 = 0;
int m_OpenGL33 = 0;
int m_OpenGL40 = 0;
int m_OpenGL41 = 0;
int m_OpenGL42 = 0;
int m_OpenGL43 = 0;
int m_OpenGL44 = 0;
int m_OpenGL45 = 0;
int m_OpenGL10 = 0;
int m_OpenGL11 = 0;
int m_GL_AMD_multi_draw_indirect = 0;
int m_GL_AMD_seamless_cubemap_per_texture = 0;
int m_GL_AMD_vertex_shader_layer = 0;
int m_GL_AMD_vertex_shader_viewport_index = 0;
int m_GL_ARB_ES2_compatibility = 0;
int m_GL_ARB_ES3_1_compatibility = 0;
int m_GL_ARB_ES3_compatibility = 0;
int m_GL_ARB_arrays_of_arrays = 0;
int m_GL_ARB_base_instance = 0;
int m_GL_ARB_bindless_texture = 0;
int m_GL_ARB_blend_func_extended = 0;
int m_GL_ARB_buffer_storage = 0;
int m_GL_ARB_clear_buffer_object = 0;
int m_GL_ARB_clear_texture = 0;
int m_GL_ARB_clip_control = 0;
int m_GL_ARB_color_buffer_float = 0;
int m_GL_ARB_compatibility = 0;
int m_GL_ARB_compressed_texture_pixel_storage = 0;
int m_GL_ARB_compute_shader = 0;
int m_GL_ARB_compute_variable_group_size = 0;
int m_GL_ARB_conditional_render_inverted = 0;
int m_GL_ARB_conservative_depth = 0;
int m_GL_ARB_copy_buffer = 0;
int m_GL_ARB_copy_image = 0;
int m_GL_ARB_cull_distance = 0;
int m_GL_ARB_debug_output = 0;
int m_GL_ARB_depth_buffer_float = 0;
int m_GL_ARB_depth_clamp = 0;
int m_GL_ARB_depth_texture = 0;
int m_GL_ARB_derivative_control = 0;
int m_GL_ARB_direct_state_access = 0;
int m_GL_ARB_draw_buffers = 0;
int m_GL_ARB_draw_buffers_blend = 0;
int m_GL_ARB_draw_elements_base_vertex = 0;
int m_GL_ARB_draw_indirect = 0;
int m_GL_ARB_draw_instanced = 0;
int m_GL_ARB_enhanced_layouts = 0;
int m_GL_ARB_explicit_attrib_location = 0;
int m_GL_ARB_explicit_uniform_location = 0;
int m_GL_ARB_fragment_coord_conventions = 0;
int m_GL_ARB_fragment_layer_viewport = 0;
int m_GL_ARB_fragment_program = 0;
int m_GL_ARB_fragment_program_shadow = 0;
int m_GL_ARB_fragment_shader = 0;
int m_GL_ARB_framebuffer_no_attachments = 0;
int m_GL_ARB_framebuffer_object = 0;
int m_GL_ARB_framebuffer_sRGB = 0;
int m_GL_ARB_geometry_shader4 = 0;
int m_GL_ARB_get_program_binary = 0;
int m_GL_ARB_get_texture_sub_image = 0;
int m_GL_ARB_gpu_shader5 = 0;
int m_GL_ARB_gpu_shader_fp64 = 0;
int m_GL_ARB_half_float_pixel = 0;
int m_GL_ARB_half_float_vertex = 0;
int m_GL_ARB_imaging = 0;
int m_GL_ARB_indirect_parameters = 0;
int m_GL_ARB_instanced_arrays = 0;
int m_GL_ARB_internalformat_query = 0;
int m_GL_ARB_internalformat_query2 = 0;
int m_GL_ARB_invalidate_subdata = 0;
int m_GL_ARB_map_buffer_alignment = 0;
int m_GL_ARB_map_buffer_range = 0;
int m_GL_ARB_multi_bind = 0;
int m_GL_ARB_multi_draw_indirect = 0;
int m_GL_ARB_multisample = 0;
int m_GL_ARB_multitexture = 0;
int m_GL_ARB_occlusion_query = 0;
int m_GL_ARB_occlusion_query2 = 0;
int m_GL_ARB_pipeline_statistics_query = 0;
int m_GL_ARB_pixel_buffer_object = 0;
int m_GL_ARB_point_parameters = 0;
int m_GL_ARB_point_sprite = 0;
int m_GL_ARB_program_interface_query = 0;
int m_GL_ARB_provoking_vertex = 0;
int m_GL_ARB_query_buffer_object = 0;
int m_GL_ARB_robust_buffer_access_behavior = 0;
int m_GL_ARB_robustness = 0;
int m_GL_ARB_sample_shading = 0;
int m_GL_ARB_sampler_objects = 0;
int m_GL_ARB_seamless_cube_map = 0;
int m_GL_ARB_seamless_cubemap_per_texture = 0;
int m_GL_ARB_separate_shader_objects = 0;
int m_GL_ARB_shader_atomic_counters = 0;
int m_GL_ARB_shader_bit_encoding = 0;
int m_GL_ARB_shader_draw_parameters = 0;
int m_GL_ARB_shader_group_vote = 0;
int m_GL_ARB_shader_image_load_store = 0;
int m_GL_ARB_shader_image_size = 0;
int m_GL_ARB_shader_objects = 0;
int m_GL_ARB_shader_precision = 0;
int m_GL_ARB_shader_storage_buffer_object = 0;
int m_GL_ARB_shader_subroutine = 0;
int m_GL_ARB_shader_texture_image_samples = 0;
int m_GL_ARB_shader_texture_lod = 0;
int m_GL_ARB_shading_language_100 = 0;
int m_GL_ARB_shading_language_420pack = 0;
int m_GL_ARB_shading_language_include = 0;
int m_GL_ARB_shading_language_packing = 0;
int m_GL_ARB_shadow = 0;
int m_GL_ARB_sparse_buffer = 0;
int m_GL_ARB_sparse_texture = 0;
int m_GL_ARB_stencil_texturing = 0;
int m_GL_ARB_sync = 0;
int m_GL_ARB_tessellation_shader = 0;
int m_GL_ARB_texture_barrier = 0;
int m_GL_ARB_texture_border_clamp = 0;
int m_GL_ARB_texture_buffer_object = 0;
int m_GL_ARB_texture_buffer_object_rgb32 = 0;
int m_GL_ARB_texture_buffer_range = 0;
int m_GL_ARB_texture_compression = 0;
int m_GL_ARB_texture_compression_bptc = 0;
int m_GL_ARB_texture_compression_rgtc = 0;
int m_GL_ARB_texture_cube_map = 0;
int m_GL_ARB_texture_cube_map_array = 0;
int m_GL_ARB_texture_env_add = 0;
int m_GL_ARB_texture_env_combine = 0;
int m_GL_ARB_texture_env_crossbar = 0;
int m_GL_ARB_texture_env_dot3 = 0;
int m_GL_ARB_texture_float = 0;
int m_GL_ARB_texture_gather = 0;
int m_GL_ARB_texture_mirror_clamp_to_edge = 0;
int m_GL_ARB_texture_mirrored_repeat = 0;
int m_GL_ARB_texture_multisample = 0;
int m_GL_ARB_texture_non_power_of_two = 0;
int m_GL_ARB_texture_query_levels = 0;
int m_GL_ARB_texture_query_lod = 0;
int m_GL_ARB_texture_rectangle = 0;
int m_GL_ARB_texture_rg = 0;
int m_GL_ARB_texture_rgb10_a2ui = 0;
int m_GL_ARB_texture_stencil8 = 0;
int m_GL_ARB_texture_storage = 0;
int m_GL_ARB_texture_storage_multisample = 0;
int m_GL_ARB_texture_swizzle = 0;
int m_GL_ARB_texture_view = 0;
int m_GL_ARB_timer_query = 0;
int m_GL_ARB_transform_feedback2 = 0;
int m_GL_ARB_transform_feedback3 = 0;
int m_GL_ARB_transform_feedback_instanced = 0;
int m_GL_ARB_transform_feedback_overflow_query = 0;
int m_GL_ARB_transpose_matrix = 0;
int m_GL_ARB_uniform_buffer_object = 0;
int m_GL_ARB_vertex_array_bgra = 0;
int m_GL_ARB_vertex_array_object = 0;
int m_GL_ARB_vertex_attrib_64bit = 0;
int m_GL_ARB_vertex_attrib_binding = 0;
int m_GL_ARB_vertex_buffer_object = 0;
int m_GL_ARB_vertex_program = 0;
int m_GL_ARB_vertex_shader = 0;
int m_GL_ARB_vertex_type_10f_11f_11f_rev = 0;
int m_GL_ARB_vertex_type_2_10_10_10_rev = 0;
int m_GL_ARB_viewport_array = 0;
int m_GL_ARB_window_pos = 0;
int m_GL_ATI_draw_buffers = 0;
int m_GL_ATI_texture_float = 0;
int m_GL_ATI_texture_mirror_once = 0;
int m_GL_EXT_abgr = 0;
int m_GL_EXT_bgra = 0;
int m_GL_EXT_bindable_uniform = 0;
int m_GL_EXT_blend_color = 0;
int m_GL_EXT_blend_equation_separate = 0;
int m_GL_EXT_blend_func_separate = 0;
int m_GL_EXT_blend_minmax = 0;
int m_GL_EXT_blend_subtract = 0;
int m_GL_EXT_compiled_vertex_array = 0;
int m_GL_EXT_depth_bounds_test = 0;
int m_GL_EXT_direct_state_access = 0;
int m_GL_EXT_draw_buffers2 = 0;
int m_GL_EXT_draw_instanced = 0;
int m_GL_EXT_draw_range_elements = 0;
int m_GL_EXT_fog_coord = 0;
int m_GL_EXT_framebuffer_blit = 0;
int m_GL_EXT_framebuffer_multisample = 0;
int m_GL_EXT_framebuffer_multisample_blit_scaled = 0;
int m_GL_EXT_framebuffer_object = 0;
int m_GL_EXT_framebuffer_sRGB = 0;
int m_GL_EXT_geometry_shader4 = 0;
int m_GL_EXT_gpu_program_parameters = 0;
int m_GL_EXT_gpu_shader4 = 0;
int m_GL_EXT_multi_draw_arrays = 0;
int m_GL_EXT_packed_depth_stencil = 0;
int m_GL_EXT_packed_float = 0;
int m_GL_EXT_packed_pixels = 0;
int m_GL_EXT_pixel_buffer_object = 0;
int m_GL_EXT_point_parameters = 0;
int m_GL_EXT_polygon_offset_clamp = 0;
int m_GL_EXT_post_depth_coverage = 0;
int m_GL_EXT_provoking_vertex = 0;
int m_GL_EXT_raster_multisample = 0;
int m_GL_EXT_rescale_normal = 0;
int m_GL_EXT_secondary_color = 0;
int m_GL_EXT_separate_shader_objects = 0;
int m_GL_EXT_separate_specular_color = 0;
int m_GL_EXT_shader_image_load_formatted = 0;
int m_GL_EXT_shader_image_load_store = 0;
int m_GL_EXT_shader_integer_mix = 0;
int m_GL_EXT_shadow_funcs = 0;
int m_GL_EXT_sparse_texture2 = 0;
int m_GL_EXT_stencil_two_side = 0;
int m_GL_EXT_stencil_wrap = 0;
int m_GL_EXT_texture3D = 0;
int m_GL_EXT_texture_array = 0;
int m_GL_EXT_texture_buffer_object = 0;
int m_GL_EXT_texture_compression_latc = 0;
int m_GL_EXT_texture_compression_rgtc = 0;
int m_GL_EXT_texture_compression_s3tc = 0;
int m_GL_EXT_texture_cube_map = 0;
int m_GL_EXT_texture_env_add = 0;
int m_GL_EXT_texture_env_combine = 0;
int m_GL_EXT_texture_env_dot3 = 0;
int m_GL_EXT_texture_filter_anisotropic = 0;
int m_GL_EXT_texture_filter_minmax = 0;
int m_GL_EXT_texture_integer = 0;
int m_GL_EXT_texture_lod_bias = 0;
int m_GL_EXT_texture_mirror_clamp = 0;
int m_GL_EXT_texture_object = 0;
int m_GL_EXT_texture_sRGB = 0;
int m_GL_EXT_texture_sRGB_decode = 0;
int m_GL_EXT_texture_shared_exponent = 0;
int m_GL_EXT_texture_swizzle = 0;
int m_GL_EXT_timer_query = 0;
int m_GL_EXT_vertex_array = 0;
int m_GL_EXT_vertex_array_bgra = 0;
int m_GL_EXT_vertex_attrib_64bit = 0;
int m_GL_EXT_x11_sync_object = 0;
int m_GL_IBM_rasterpos_clip = 0;
int m_GL_IBM_texture_mirrored_repeat = 0;
int m_GL_KHR_blend_equation_advanced = 0;
int m_GL_KHR_blend_equation_advanced_coherent = 0;
int m_GL_KHR_context_flush_control = 0;
int m_GL_KHR_debug = 0;
int m_GL_KHR_robust_buffer_access_behavior = 0;
int m_GL_KHR_robustness = 0;
int m_GL_NVX_conditional_render = 0;
int m_GL_NVX_gpu_memory_info = 0;
int m_GL_NV_bindless_multi_draw_indirect = 0;
int m_GL_NV_bindless_multi_draw_indirect_count = 0;
int m_GL_NV_bindless_texture = 0;
int m_GL_NV_blend_equation_advanced = 0;
int m_GL_NV_blend_equation_advanced_coherent = 0;
int m_GL_NV_blend_square = 0;
int m_GL_NV_command_list = 0;
int m_GL_NV_compute_program5 = 0;
int m_GL_NV_conditional_render = 0;
int m_GL_NV_conservative_raster = 0;
int m_GL_NV_conservative_raster_dilate = 0;
int m_GL_NV_copy_depth_to_color = 0;
int m_GL_NV_copy_image = 0;
int m_GL_NV_depth_buffer_float = 0;
int m_GL_NV_depth_clamp = 0;
int m_GL_NV_draw_texture = 0;
int m_GL_NV_explicit_multisample = 0;
int m_GL_NV_fence = 0;
int m_GL_NV_fill_rectangle = 0;
int m_GL_NV_float_buffer = 0;
int m_GL_NV_fog_distance = 0;
int m_GL_NV_fragment_coverage_to_color = 0;
int m_GL_NV_fragment_program = 0;
int m_GL_NV_fragment_program2 = 0;
int m_GL_NV_fragment_program_option = 0;
int m_GL_NV_fragment_shader_interlock = 0;
int m_GL_NV_framebuffer_mixed_samples = 0;
int m_GL_NV_framebuffer_multisample_coverage = 0;
int m_GL_NV_geometry_shader4 = 0;
int m_GL_NV_geometry_shader_passthrough = 0;
int m_GL_NV_gpu_program4 = 0;
int m_GL_NV_gpu_program5 = 0;
int m_GL_NV_gpu_program5_mem_extended = 0;
int m_GL_NV_gpu_shader5 = 0;
int m_GL_NV_half_float = 0;
int m_GL_NV_internalformat_sample_query = 0;
int m_GL_NV_light_max_exponent = 0;
int m_GL_NV_multisample_coverage = 0;
int m_GL_NV_multisample_filter_hint = 0;
int m_GL_NV_occlusion_query = 0;
int m_GL_NV_packed_depth_stencil = 0;
int m_GL_NV_parameter_buffer_object = 0;
int m_GL_NV_parameter_buffer_object2 = 0;
int m_GL_NV_path_rendering = 0;
int m_GL_NV_path_rendering_shared_edge = 0;
int m_GL_NV_pixel_data_range = 0;
int m_GL_NV_point_sprite = 0;
int m_GL_NV_primitive_restart = 0;
int m_GL_NV_register_combiners = 0;
int m_GL_NV_register_combiners2 = 0;
int m_GL_NV_sample_locations = 0;
int m_GL_NV_sample_mask_override_coverage = 0;
int m_GL_NV_shader_atomic_counters = 0;
int m_GL_NV_shader_atomic_float = 0;
int m_GL_NV_shader_atomic_fp16_vector = 0;
int m_GL_NV_shader_atomic_int64 = 0;
int m_GL_NV_shader_buffer_load = 0;
int m_GL_NV_shader_storage_buffer_object = 0;
int m_GL_NV_shader_thread_group = 0;
int m_GL_NV_shader_thread_shuffle = 0;
int m_GL_NV_texgen_reflection = 0;
int m_GL_NV_texture_barrier = 0;
int m_GL_NV_texture_compression_vtc = 0;
int m_GL_NV_texture_env_combine4 = 0;
int m_GL_NV_texture_multisample = 0;
int m_GL_NV_texture_rectangle = 0;
int m_GL_NV_texture_shader = 0;
int m_GL_NV_texture_shader2 = 0;
int m_GL_NV_texture_shader3 = 0;
int m_GL_NV_transform_feedback = 0;
int m_GL_NV_transform_feedback2 = 0;
int m_GL_NV_uniform_buffer_unified_memory = 0;
int m_GL_NV_vdpau_interop = 0;
int m_GL_NV_vertex_array_range = 0;
int m_GL_NV_vertex_array_range2 = 0;
int m_GL_NV_vertex_attrib_integer_64bit = 0;
int m_GL_NV_vertex_buffer_unified_memory = 0;
int m_GL_NV_vertex_program = 0;
int m_GL_NV_vertex_program1_1 = 0;
int m_GL_NV_vertex_program2 = 0;
int m_GL_NV_vertex_program2_option = 0;
int m_GL_NV_vertex_program3 = 0;
int m_GL_NV_viewport_array2 = 0;
int m_GL_S3_s3tc = 0;
int m_GL_SGIS_generate_mipmap = 0;
int m_GL_SGIS_texture_lod = 0;
int m_GL_SGIX_depth_texture = 0;
int m_GL_SGIX_shadow = 0;
int m_GL_SUN_slice_accum = 0;

#ifdef _GLX

int m_GLX_ARB_context_flush_control = 0;
int m_GLX_ARB_create_context = 0;
int m_GLX_ARB_create_context_profile = 0;
int m_GLX_ARB_create_context_robustness = 0;
int m_GLX_ARB_fbconfig_float = 0;
int m_GLX_ARB_multisample = 0;
int m_GLX_EXT_buffer_age = 0;
int m_GLX_EXT_create_context_es2_profile = 0;
int m_GLX_EXT_create_context_es_profile = 0;
int m_GLX_EXT_fbconfig_packed_float = 0;
int m_GLX_EXT_framebuffer_sRGB = 0;
int m_GLX_EXT_import_context = 0;
int m_GLX_EXT_stereo_tree = 0;
int m_GLX_EXT_swap_control = 0;
int m_GLX_EXT_swap_control_tear = 0;
int m_GLX_EXT_texture_from_pixmap = 0;
int m_GLX_EXT_visual_info = 0;
int m_GLX_EXT_visual_rating = 0;
int m_GLX_NV_copy_buffer = 0;
int m_GLX_NV_copy_image = 0;
int m_GLX_NV_delay_before_swap = 0;
int m_GLX_NV_float_buffer = 0;
int m_GLX_NV_multisample_coverage = 0;
int m_GLX_NV_present_video = 0;
int m_GLX_NV_swap_group = 0;
int m_GLX_NV_video_capture = 0;
int m_GLX_NV_video_out = 0;
int m_GLX_SGIX_fbconfig = 0;
int m_GLX_SGIX_pbuffer = 0;
int m_GLX_SGI_swap_control = 0;
int m_GLX_SGI_video_sync = 0;

#endif		//_GLX

// ----------------------------------------------------------------------------
// Find the call address of a WGL or GLX extension function
// ----------------------------------------------------------------------------

void *GetGLProcAddress( char *buf )
{
#ifdef _WIN32
	return( wglGetProcAddress( buf ) );
#endif

#ifdef _GLX
	return( (void *) glXGetProcAddressARB( (const GLubyte *) buf ) );
#endif

return( NULL );
}

// --------------------------------------------------------------------------
// Routines to search for an extension string in another string
//
// Inputs: None
//
// Outputs: None
//
// Results: 1 is returned if the substring is found, 0 otherwise
//
// Effects: None
// --------------------------------------------------------------------------

int StringSearch( char *pext, char *pstring )
{
char *pstart, *pend;
int len;

if ( !(pstart = strstr( pext, pstring ) ) )
	return( 0 );

if ( (pstart > pext) && (pstart[-1] != ' ') )
	 return( 0 );

len  = strlen(pstring);
pend = pstart + len;

while ( pstart && (*pend != ' ') && (*pend != '\0') )
    {
	 pstart = strstr( pend, pstring );

	 if ( pstart )
        pend   = pstart + len;
	 else
        pend = NULL;
	 }

if ( !pend )
    return( 0 );

if ( (*pend != ' ') && (*pend != '\0' ) )
    return( 0 );

return( 1 );
}

// --------------------------------------------------------------------------
// Routine to check the presence of an OpenGL extension
//
// Inputs: None
//
// Outputs: None
//
// Results: 1 is returned if the extension exists, 0 otherwise
//
// Effects: None
// --------------------------------------------------------------------------

int CheckGLExtension( char *pchname )
{
GLubyte *pextstring = (GLubyte *) glGetString(GL_EXTENSIONS);

return( StringSearch( (char *) pextstring, (char *) pchname ) );
}

// --------------------------------------------------------------------------
// Routine to check whether an OpenGL version is supported
// The OpenGL version is specified using integer format <hi>.<lo>
//
// Inputs: shi - first integer <hi>
//         slo - second integer <lo>
//
// Outputs: None
//
// Results: true if the version is supported, false otherwise
// --------------------------------------------------------------------------

bool CheckGLVersion( unsigned int shi, unsigned int slo )
{
unsigned int dlo, dhi, dvlo;

// Get the device driver number
GLubyte *pextstring = (GLubyte *) glGetString(GL_VERSION);

sscanf( (char *) pextstring, "%d.%d.%d", &dhi, &dlo, &dvlo);

return (dhi > shi) || ((dhi == shi) && (dlo >= slo));
}

// --------------------------------------------------------------------------
// Routine to check the OpenGL Version
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: Status flags are set according to the OpenGL version present
// --------------------------------------------------------------------------

void CheckOpenGLVersion( void )
{
m_OpenGL12 = CheckGLVersion( 1, 2 );
m_OpenGL13 = CheckGLVersion( 1, 3 );
m_OpenGL14 = CheckGLVersion( 1, 4 );
m_OpenGL15 = CheckGLVersion( 1, 5 );
m_OpenGL20 = CheckGLVersion( 2, 0 );
m_OpenGL21 = CheckGLVersion( 2, 1 );
m_OpenGL30 = CheckGLVersion( 3, 0 );
m_OpenGL31 = CheckGLVersion( 3, 1 );
m_OpenGL32 = CheckGLVersion( 3, 2 );
m_OpenGL33 = CheckGLVersion( 3, 3 );
m_OpenGL40 = CheckGLVersion( 4, 0 );
m_OpenGL41 = CheckGLVersion( 4, 1 );
m_OpenGL42 = CheckGLVersion( 4, 2 );
m_OpenGL43 = CheckGLVersion( 4, 3 );
m_OpenGL44 = CheckGLVersion( 4, 4 );
m_OpenGL45 = CheckGLVersion( 4, 5 );
m_OpenGL10 = CheckGLVersion( 1, 0 );
m_OpenGL11 = CheckGLVersion( 1, 1 );
}

// --------------------------------------------------------------------------
// Routine to check the OpenGL Extensions
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: Status flags are set according to the OpenGL version present
// --------------------------------------------------------------------------

void CheckOpenGLExtensions( void )
{
m_GL_AMD_multi_draw_indirect = CheckGLExtension( "GL_AMD_multi_draw_indirect" );
m_GL_AMD_seamless_cubemap_per_texture = CheckGLExtension( "GL_AMD_seamless_cubemap_per_texture" );
m_GL_AMD_vertex_shader_layer = CheckGLExtension( "GL_AMD_vertex_shader_layer" );
m_GL_AMD_vertex_shader_viewport_index = CheckGLExtension( "GL_AMD_vertex_shader_viewport_index" );
m_GL_ARB_ES2_compatibility = CheckGLExtension( "GL_ARB_ES2_compatibility" );
m_GL_ARB_ES3_1_compatibility = CheckGLExtension( "GL_ARB_ES3_1_compatibility" );
m_GL_ARB_ES3_compatibility = CheckGLExtension( "GL_ARB_ES3_compatibility" );
m_GL_ARB_arrays_of_arrays = CheckGLExtension( "GL_ARB_arrays_of_arrays" );
m_GL_ARB_base_instance = CheckGLExtension( "GL_ARB_base_instance" );
m_GL_ARB_bindless_texture = CheckGLExtension( "GL_ARB_bindless_texture" );
m_GL_ARB_blend_func_extended = CheckGLExtension( "GL_ARB_blend_func_extended" );
m_GL_ARB_buffer_storage = CheckGLExtension( "GL_ARB_buffer_storage" );
m_GL_ARB_clear_buffer_object = CheckGLExtension( "GL_ARB_clear_buffer_object" );
m_GL_ARB_clear_texture = CheckGLExtension( "GL_ARB_clear_texture" );
m_GL_ARB_clip_control = CheckGLExtension( "GL_ARB_clip_control" );
m_GL_ARB_color_buffer_float = CheckGLExtension( "GL_ARB_color_buffer_float" );
m_GL_ARB_compatibility = CheckGLExtension( "GL_ARB_compatibility" );
m_GL_ARB_compressed_texture_pixel_storage = CheckGLExtension( "GL_ARB_compressed_texture_pixel_storage" );
m_GL_ARB_compute_shader = CheckGLExtension( "GL_ARB_compute_shader" );
m_GL_ARB_compute_variable_group_size = CheckGLExtension( "GL_ARB_compute_variable_group_size" );
m_GL_ARB_conditional_render_inverted = CheckGLExtension( "GL_ARB_conditional_render_inverted" );
m_GL_ARB_conservative_depth = CheckGLExtension( "GL_ARB_conservative_depth" );
m_GL_ARB_copy_buffer = CheckGLExtension( "GL_ARB_copy_buffer" );
m_GL_ARB_copy_image = CheckGLExtension( "GL_ARB_copy_image" );
m_GL_ARB_cull_distance = CheckGLExtension( "GL_ARB_cull_distance" );
m_GL_ARB_debug_output = CheckGLExtension( "GL_ARB_debug_output" );
m_GL_ARB_depth_buffer_float = CheckGLExtension( "GL_ARB_depth_buffer_float" );
m_GL_ARB_depth_clamp = CheckGLExtension( "GL_ARB_depth_clamp" );
m_GL_ARB_depth_texture = CheckGLExtension( "GL_ARB_depth_texture" );
m_GL_ARB_derivative_control = CheckGLExtension( "GL_ARB_derivative_control" );
m_GL_ARB_direct_state_access = CheckGLExtension( "GL_ARB_direct_state_access" );
m_GL_ARB_draw_buffers = CheckGLExtension( "GL_ARB_draw_buffers" );
m_GL_ARB_draw_buffers_blend = CheckGLExtension( "GL_ARB_draw_buffers_blend" );
m_GL_ARB_draw_elements_base_vertex = CheckGLExtension( "GL_ARB_draw_elements_base_vertex" );
m_GL_ARB_draw_indirect = CheckGLExtension( "GL_ARB_draw_indirect" );
m_GL_ARB_draw_instanced = CheckGLExtension( "GL_ARB_draw_instanced" );
m_GL_ARB_enhanced_layouts = CheckGLExtension( "GL_ARB_enhanced_layouts" );
m_GL_ARB_explicit_attrib_location = CheckGLExtension( "GL_ARB_explicit_attrib_location" );
m_GL_ARB_explicit_uniform_location = CheckGLExtension( "GL_ARB_explicit_uniform_location" );
m_GL_ARB_fragment_coord_conventions = CheckGLExtension( "GL_ARB_fragment_coord_conventions" );
m_GL_ARB_fragment_layer_viewport = CheckGLExtension( "GL_ARB_fragment_layer_viewport" );
m_GL_ARB_fragment_program = CheckGLExtension( "GL_ARB_fragment_program" );
m_GL_ARB_fragment_program_shadow = CheckGLExtension( "GL_ARB_fragment_program_shadow" );
m_GL_ARB_fragment_shader = CheckGLExtension( "GL_ARB_fragment_shader" );
m_GL_ARB_framebuffer_no_attachments = CheckGLExtension( "GL_ARB_framebuffer_no_attachments" );
m_GL_ARB_framebuffer_object = CheckGLExtension( "GL_ARB_framebuffer_object" );
m_GL_ARB_framebuffer_sRGB = CheckGLExtension( "GL_ARB_framebuffer_sRGB" );
m_GL_ARB_geometry_shader4 = CheckGLExtension( "GL_ARB_geometry_shader4" );
m_GL_ARB_get_program_binary = CheckGLExtension( "GL_ARB_get_program_binary" );
m_GL_ARB_get_texture_sub_image = CheckGLExtension( "GL_ARB_get_texture_sub_image" );
m_GL_ARB_gpu_shader5 = CheckGLExtension( "GL_ARB_gpu_shader5" );
m_GL_ARB_gpu_shader_fp64 = CheckGLExtension( "GL_ARB_gpu_shader_fp64" );
m_GL_ARB_half_float_pixel = CheckGLExtension( "GL_ARB_half_float_pixel" );
m_GL_ARB_half_float_vertex = CheckGLExtension( "GL_ARB_half_float_vertex" );
m_GL_ARB_imaging = CheckGLExtension( "GL_ARB_imaging" );
m_GL_ARB_indirect_parameters = CheckGLExtension( "GL_ARB_indirect_parameters" );
m_GL_ARB_instanced_arrays = CheckGLExtension( "GL_ARB_instanced_arrays" );
m_GL_ARB_internalformat_query = CheckGLExtension( "GL_ARB_internalformat_query" );
m_GL_ARB_internalformat_query2 = CheckGLExtension( "GL_ARB_internalformat_query2" );
m_GL_ARB_invalidate_subdata = CheckGLExtension( "GL_ARB_invalidate_subdata" );
m_GL_ARB_map_buffer_alignment = CheckGLExtension( "GL_ARB_map_buffer_alignment" );
m_GL_ARB_map_buffer_range = CheckGLExtension( "GL_ARB_map_buffer_range" );
m_GL_ARB_multi_bind = CheckGLExtension( "GL_ARB_multi_bind" );
m_GL_ARB_multi_draw_indirect = CheckGLExtension( "GL_ARB_multi_draw_indirect" );
m_GL_ARB_multisample = CheckGLExtension( "GL_ARB_multisample" );
m_GL_ARB_multitexture = CheckGLExtension( "GL_ARB_multitexture" );
m_GL_ARB_occlusion_query = CheckGLExtension( "GL_ARB_occlusion_query" );
m_GL_ARB_occlusion_query2 = CheckGLExtension( "GL_ARB_occlusion_query2" );
m_GL_ARB_pipeline_statistics_query = CheckGLExtension( "GL_ARB_pipeline_statistics_query" );
m_GL_ARB_pixel_buffer_object = CheckGLExtension( "GL_ARB_pixel_buffer_object" );
m_GL_ARB_point_parameters = CheckGLExtension( "GL_ARB_point_parameters" );
m_GL_ARB_point_sprite = CheckGLExtension( "GL_ARB_point_sprite" );
m_GL_ARB_program_interface_query = CheckGLExtension( "GL_ARB_program_interface_query" );
m_GL_ARB_provoking_vertex = CheckGLExtension( "GL_ARB_provoking_vertex" );
m_GL_ARB_query_buffer_object = CheckGLExtension( "GL_ARB_query_buffer_object" );
m_GL_ARB_robust_buffer_access_behavior = CheckGLExtension( "GL_ARB_robust_buffer_access_behavior" );
m_GL_ARB_robustness = CheckGLExtension( "GL_ARB_robustness" );
m_GL_ARB_sample_shading = CheckGLExtension( "GL_ARB_sample_shading" );
m_GL_ARB_sampler_objects = CheckGLExtension( "GL_ARB_sampler_objects" );
m_GL_ARB_seamless_cube_map = CheckGLExtension( "GL_ARB_seamless_cube_map" );
m_GL_ARB_seamless_cubemap_per_texture = CheckGLExtension( "GL_ARB_seamless_cubemap_per_texture" );
m_GL_ARB_separate_shader_objects = CheckGLExtension( "GL_ARB_separate_shader_objects" );
m_GL_ARB_shader_atomic_counters = CheckGLExtension( "GL_ARB_shader_atomic_counters" );
m_GL_ARB_shader_bit_encoding = CheckGLExtension( "GL_ARB_shader_bit_encoding" );
m_GL_ARB_shader_draw_parameters = CheckGLExtension( "GL_ARB_shader_draw_parameters" );
m_GL_ARB_shader_group_vote = CheckGLExtension( "GL_ARB_shader_group_vote" );
m_GL_ARB_shader_image_load_store = CheckGLExtension( "GL_ARB_shader_image_load_store" );
m_GL_ARB_shader_image_size = CheckGLExtension( "GL_ARB_shader_image_size" );
m_GL_ARB_shader_objects = CheckGLExtension( "GL_ARB_shader_objects" );
m_GL_ARB_shader_precision = CheckGLExtension( "GL_ARB_shader_precision" );
m_GL_ARB_shader_storage_buffer_object = CheckGLExtension( "GL_ARB_shader_storage_buffer_object" );
m_GL_ARB_shader_subroutine = CheckGLExtension( "GL_ARB_shader_subroutine" );
m_GL_ARB_shader_texture_image_samples = CheckGLExtension( "GL_ARB_shader_texture_image_samples" );
m_GL_ARB_shader_texture_lod = CheckGLExtension( "GL_ARB_shader_texture_lod" );
m_GL_ARB_shading_language_100 = CheckGLExtension( "GL_ARB_shading_language_100" );
m_GL_ARB_shading_language_420pack = CheckGLExtension( "GL_ARB_shading_language_420pack" );
m_GL_ARB_shading_language_include = CheckGLExtension( "GL_ARB_shading_language_include" );
m_GL_ARB_shading_language_packing = CheckGLExtension( "GL_ARB_shading_language_packing" );
m_GL_ARB_shadow = CheckGLExtension( "GL_ARB_shadow" );
m_GL_ARB_sparse_buffer = CheckGLExtension( "GL_ARB_sparse_buffer" );
m_GL_ARB_sparse_texture = CheckGLExtension( "GL_ARB_sparse_texture" );
m_GL_ARB_stencil_texturing = CheckGLExtension( "GL_ARB_stencil_texturing" );
m_GL_ARB_sync = CheckGLExtension( "GL_ARB_sync" );
m_GL_ARB_tessellation_shader = CheckGLExtension( "GL_ARB_tessellation_shader" );
m_GL_ARB_texture_barrier = CheckGLExtension( "GL_ARB_texture_barrier" );
m_GL_ARB_texture_border_clamp = CheckGLExtension( "GL_ARB_texture_border_clamp" );
m_GL_ARB_texture_buffer_object = CheckGLExtension( "GL_ARB_texture_buffer_object" );
m_GL_ARB_texture_buffer_object_rgb32 = CheckGLExtension( "GL_ARB_texture_buffer_object_rgb32" );
m_GL_ARB_texture_buffer_range = CheckGLExtension( "GL_ARB_texture_buffer_range" );
m_GL_ARB_texture_compression = CheckGLExtension( "GL_ARB_texture_compression" );
m_GL_ARB_texture_compression_bptc = CheckGLExtension( "GL_ARB_texture_compression_bptc" );
m_GL_ARB_texture_compression_rgtc = CheckGLExtension( "GL_ARB_texture_compression_rgtc" );
m_GL_ARB_texture_cube_map = CheckGLExtension( "GL_ARB_texture_cube_map" );
m_GL_ARB_texture_cube_map_array = CheckGLExtension( "GL_ARB_texture_cube_map_array" );
m_GL_ARB_texture_env_add = CheckGLExtension( "GL_ARB_texture_env_add" );
m_GL_ARB_texture_env_combine = CheckGLExtension( "GL_ARB_texture_env_combine" );
m_GL_ARB_texture_env_crossbar = CheckGLExtension( "GL_ARB_texture_env_crossbar" );
m_GL_ARB_texture_env_dot3 = CheckGLExtension( "GL_ARB_texture_env_dot3" );
m_GL_ARB_texture_float = CheckGLExtension( "GL_ARB_texture_float" );
m_GL_ARB_texture_gather = CheckGLExtension( "GL_ARB_texture_gather" );
m_GL_ARB_texture_mirror_clamp_to_edge = CheckGLExtension( "GL_ARB_texture_mirror_clamp_to_edge" );
m_GL_ARB_texture_mirrored_repeat = CheckGLExtension( "GL_ARB_texture_mirrored_repeat" );
m_GL_ARB_texture_multisample = CheckGLExtension( "GL_ARB_texture_multisample" );
m_GL_ARB_texture_non_power_of_two = CheckGLExtension( "GL_ARB_texture_non_power_of_two" );
m_GL_ARB_texture_query_levels = CheckGLExtension( "GL_ARB_texture_query_levels" );
m_GL_ARB_texture_query_lod = CheckGLExtension( "GL_ARB_texture_query_lod" );
m_GL_ARB_texture_rectangle = CheckGLExtension( "GL_ARB_texture_rectangle" );
m_GL_ARB_texture_rg = CheckGLExtension( "GL_ARB_texture_rg" );
m_GL_ARB_texture_rgb10_a2ui = CheckGLExtension( "GL_ARB_texture_rgb10_a2ui" );
m_GL_ARB_texture_stencil8 = CheckGLExtension( "GL_ARB_texture_stencil8" );
m_GL_ARB_texture_storage = CheckGLExtension( "GL_ARB_texture_storage" );
m_GL_ARB_texture_storage_multisample = CheckGLExtension( "GL_ARB_texture_storage_multisample" );
m_GL_ARB_texture_swizzle = CheckGLExtension( "GL_ARB_texture_swizzle" );
m_GL_ARB_texture_view = CheckGLExtension( "GL_ARB_texture_view" );
m_GL_ARB_timer_query = CheckGLExtension( "GL_ARB_timer_query" );
m_GL_ARB_transform_feedback2 = CheckGLExtension( "GL_ARB_transform_feedback2" );
m_GL_ARB_transform_feedback3 = CheckGLExtension( "GL_ARB_transform_feedback3" );
m_GL_ARB_transform_feedback_instanced = CheckGLExtension( "GL_ARB_transform_feedback_instanced" );
m_GL_ARB_transform_feedback_overflow_query = CheckGLExtension( "GL_ARB_transform_feedback_overflow_query" );
m_GL_ARB_transpose_matrix = CheckGLExtension( "GL_ARB_transpose_matrix" );
m_GL_ARB_uniform_buffer_object = CheckGLExtension( "GL_ARB_uniform_buffer_object" );
m_GL_ARB_vertex_array_bgra = CheckGLExtension( "GL_ARB_vertex_array_bgra" );
m_GL_ARB_vertex_array_object = CheckGLExtension( "GL_ARB_vertex_array_object" );
m_GL_ARB_vertex_attrib_64bit = CheckGLExtension( "GL_ARB_vertex_attrib_64bit" );
m_GL_ARB_vertex_attrib_binding = CheckGLExtension( "GL_ARB_vertex_attrib_binding" );
m_GL_ARB_vertex_buffer_object = CheckGLExtension( "GL_ARB_vertex_buffer_object" );
m_GL_ARB_vertex_program = CheckGLExtension( "GL_ARB_vertex_program" );
m_GL_ARB_vertex_shader = CheckGLExtension( "GL_ARB_vertex_shader" );
m_GL_ARB_vertex_type_10f_11f_11f_rev = CheckGLExtension( "GL_ARB_vertex_type_10f_11f_11f_rev" );
m_GL_ARB_vertex_type_2_10_10_10_rev = CheckGLExtension( "GL_ARB_vertex_type_2_10_10_10_rev" );
m_GL_ARB_viewport_array = CheckGLExtension( "GL_ARB_viewport_array" );
m_GL_ARB_window_pos = CheckGLExtension( "GL_ARB_window_pos" );
m_GL_ATI_draw_buffers = CheckGLExtension( "GL_ATI_draw_buffers" );
m_GL_ATI_texture_float = CheckGLExtension( "GL_ATI_texture_float" );
m_GL_ATI_texture_mirror_once = CheckGLExtension( "GL_ATI_texture_mirror_once" );
m_GL_EXT_abgr = CheckGLExtension( "GL_EXT_abgr" );
m_GL_EXT_bgra = CheckGLExtension( "GL_EXT_bgra" );
m_GL_EXT_bindable_uniform = CheckGLExtension( "GL_EXT_bindable_uniform" );
m_GL_EXT_blend_color = CheckGLExtension( "GL_EXT_blend_color" );
m_GL_EXT_blend_equation_separate = CheckGLExtension( "GL_EXT_blend_equation_separate" );
m_GL_EXT_blend_func_separate = CheckGLExtension( "GL_EXT_blend_func_separate" );
m_GL_EXT_blend_minmax = CheckGLExtension( "GL_EXT_blend_minmax" );
m_GL_EXT_blend_subtract = CheckGLExtension( "GL_EXT_blend_subtract" );
m_GL_EXT_compiled_vertex_array = CheckGLExtension( "GL_EXT_compiled_vertex_array" );
m_GL_EXT_depth_bounds_test = CheckGLExtension( "GL_EXT_depth_bounds_test" );
m_GL_EXT_direct_state_access = CheckGLExtension( "GL_EXT_direct_state_access" );
m_GL_EXT_draw_buffers2 = CheckGLExtension( "GL_EXT_draw_buffers2" );
m_GL_EXT_draw_instanced = CheckGLExtension( "GL_EXT_draw_instanced" );
m_GL_EXT_draw_range_elements = CheckGLExtension( "GL_EXT_draw_range_elements" );
m_GL_EXT_fog_coord = CheckGLExtension( "GL_EXT_fog_coord" );
m_GL_EXT_framebuffer_blit = CheckGLExtension( "GL_EXT_framebuffer_blit" );
m_GL_EXT_framebuffer_multisample = CheckGLExtension( "GL_EXT_framebuffer_multisample" );
m_GL_EXT_framebuffer_multisample_blit_scaled = CheckGLExtension( "GL_EXT_framebuffer_multisample_blit_scaled" );
m_GL_EXT_framebuffer_object = CheckGLExtension( "GL_EXT_framebuffer_object" );
m_GL_EXT_framebuffer_sRGB = CheckGLExtension( "GL_EXT_framebuffer_sRGB" );
m_GL_EXT_geometry_shader4 = CheckGLExtension( "GL_EXT_geometry_shader4" );
m_GL_EXT_gpu_program_parameters = CheckGLExtension( "GL_EXT_gpu_program_parameters" );
m_GL_EXT_gpu_shader4 = CheckGLExtension( "GL_EXT_gpu_shader4" );
m_GL_EXT_multi_draw_arrays = CheckGLExtension( "GL_EXT_multi_draw_arrays" );
m_GL_EXT_packed_depth_stencil = CheckGLExtension( "GL_EXT_packed_depth_stencil" );
m_GL_EXT_packed_float = CheckGLExtension( "GL_EXT_packed_float" );
m_GL_EXT_packed_pixels = CheckGLExtension( "GL_EXT_packed_pixels" );
m_GL_EXT_pixel_buffer_object = CheckGLExtension( "GL_EXT_pixel_buffer_object" );
m_GL_EXT_point_parameters = CheckGLExtension( "GL_EXT_point_parameters" );
m_GL_EXT_polygon_offset_clamp = CheckGLExtension( "GL_EXT_polygon_offset_clamp" );
m_GL_EXT_post_depth_coverage = CheckGLExtension( "GL_EXT_post_depth_coverage" );
m_GL_EXT_provoking_vertex = CheckGLExtension( "GL_EXT_provoking_vertex" );
m_GL_EXT_raster_multisample = CheckGLExtension( "GL_EXT_raster_multisample" );
m_GL_EXT_rescale_normal = CheckGLExtension( "GL_EXT_rescale_normal" );
m_GL_EXT_secondary_color = CheckGLExtension( "GL_EXT_secondary_color" );
m_GL_EXT_separate_shader_objects = CheckGLExtension( "GL_EXT_separate_shader_objects" );
m_GL_EXT_separate_specular_color = CheckGLExtension( "GL_EXT_separate_specular_color" );
m_GL_EXT_shader_image_load_formatted = CheckGLExtension( "GL_EXT_shader_image_load_formatted" );
m_GL_EXT_shader_image_load_store = CheckGLExtension( "GL_EXT_shader_image_load_store" );
m_GL_EXT_shader_integer_mix = CheckGLExtension( "GL_EXT_shader_integer_mix" );
m_GL_EXT_shadow_funcs = CheckGLExtension( "GL_EXT_shadow_funcs" );
m_GL_EXT_sparse_texture2 = CheckGLExtension( "GL_EXT_sparse_texture2" );
m_GL_EXT_stencil_two_side = CheckGLExtension( "GL_EXT_stencil_two_side" );
m_GL_EXT_stencil_wrap = CheckGLExtension( "GL_EXT_stencil_wrap" );
m_GL_EXT_texture3D = CheckGLExtension( "GL_EXT_texture3D" );
m_GL_EXT_texture_array = CheckGLExtension( "GL_EXT_texture_array" );
m_GL_EXT_texture_buffer_object = CheckGLExtension( "GL_EXT_texture_buffer_object" );
m_GL_EXT_texture_compression_latc = CheckGLExtension( "GL_EXT_texture_compression_latc" );
m_GL_EXT_texture_compression_rgtc = CheckGLExtension( "GL_EXT_texture_compression_rgtc" );
m_GL_EXT_texture_compression_s3tc = CheckGLExtension( "GL_EXT_texture_compression_s3tc" );
m_GL_EXT_texture_cube_map = CheckGLExtension( "GL_EXT_texture_cube_map" );
m_GL_EXT_texture_env_add = CheckGLExtension( "GL_EXT_texture_env_add" );
m_GL_EXT_texture_env_combine = CheckGLExtension( "GL_EXT_texture_env_combine" );
m_GL_EXT_texture_env_dot3 = CheckGLExtension( "GL_EXT_texture_env_dot3" );
m_GL_EXT_texture_filter_anisotropic = CheckGLExtension( "GL_EXT_texture_filter_anisotropic" );
m_GL_EXT_texture_filter_minmax = CheckGLExtension( "GL_EXT_texture_filter_minmax" );
m_GL_EXT_texture_integer = CheckGLExtension( "GL_EXT_texture_integer" );
m_GL_EXT_texture_lod_bias = CheckGLExtension( "GL_EXT_texture_lod_bias" );
m_GL_EXT_texture_mirror_clamp = CheckGLExtension( "GL_EXT_texture_mirror_clamp" );
m_GL_EXT_texture_object = CheckGLExtension( "GL_EXT_texture_object" );
m_GL_EXT_texture_sRGB = CheckGLExtension( "GL_EXT_texture_sRGB" );
m_GL_EXT_texture_sRGB_decode = CheckGLExtension( "GL_EXT_texture_sRGB_decode" );
m_GL_EXT_texture_shared_exponent = CheckGLExtension( "GL_EXT_texture_shared_exponent" );
m_GL_EXT_texture_swizzle = CheckGLExtension( "GL_EXT_texture_swizzle" );
m_GL_EXT_timer_query = CheckGLExtension( "GL_EXT_timer_query" );
m_GL_EXT_vertex_array = CheckGLExtension( "GL_EXT_vertex_array" );
m_GL_EXT_vertex_array_bgra = CheckGLExtension( "GL_EXT_vertex_array_bgra" );
m_GL_EXT_vertex_attrib_64bit = CheckGLExtension( "GL_EXT_vertex_attrib_64bit" );
m_GL_EXT_x11_sync_object = CheckGLExtension( "GL_EXT_x11_sync_object" );
m_GL_IBM_rasterpos_clip = CheckGLExtension( "GL_IBM_rasterpos_clip" );
m_GL_IBM_texture_mirrored_repeat = CheckGLExtension( "GL_IBM_texture_mirrored_repeat" );
m_GL_KHR_blend_equation_advanced = CheckGLExtension( "GL_KHR_blend_equation_advanced" );
m_GL_KHR_blend_equation_advanced_coherent = CheckGLExtension( "GL_KHR_blend_equation_advanced_coherent" );
m_GL_KHR_context_flush_control = CheckGLExtension( "GL_KHR_context_flush_control" );
m_GL_KHR_debug = CheckGLExtension( "GL_KHR_debug" );
m_GL_KHR_robust_buffer_access_behavior = CheckGLExtension( "GL_KHR_robust_buffer_access_behavior" );
m_GL_KHR_robustness = CheckGLExtension( "GL_KHR_robustness" );
m_GL_NVX_conditional_render = CheckGLExtension( "GL_NVX_conditional_render" );
m_GL_NVX_gpu_memory_info = CheckGLExtension( "GL_NVX_gpu_memory_info" );
m_GL_NV_bindless_multi_draw_indirect = CheckGLExtension( "GL_NV_bindless_multi_draw_indirect" );
m_GL_NV_bindless_multi_draw_indirect_count = CheckGLExtension( "GL_NV_bindless_multi_draw_indirect_count" );
m_GL_NV_bindless_texture = CheckGLExtension( "GL_NV_bindless_texture" );
m_GL_NV_blend_equation_advanced = CheckGLExtension( "GL_NV_blend_equation_advanced" );
m_GL_NV_blend_equation_advanced_coherent = CheckGLExtension( "GL_NV_blend_equation_advanced_coherent" );
m_GL_NV_blend_square = CheckGLExtension( "GL_NV_blend_square" );
m_GL_NV_command_list = CheckGLExtension( "GL_NV_command_list" );
m_GL_NV_compute_program5 = CheckGLExtension( "GL_NV_compute_program5" );
m_GL_NV_conditional_render = CheckGLExtension( "GL_NV_conditional_render" );
m_GL_NV_conservative_raster = CheckGLExtension( "GL_NV_conservative_raster" );
m_GL_NV_conservative_raster_dilate = CheckGLExtension( "GL_NV_conservative_raster_dilate" );
m_GL_NV_copy_depth_to_color = CheckGLExtension( "GL_NV_copy_depth_to_color" );
m_GL_NV_copy_image = CheckGLExtension( "GL_NV_copy_image" );
m_GL_NV_depth_buffer_float = CheckGLExtension( "GL_NV_depth_buffer_float" );
m_GL_NV_depth_clamp = CheckGLExtension( "GL_NV_depth_clamp" );
m_GL_NV_draw_texture = CheckGLExtension( "GL_NV_draw_texture" );
m_GL_NV_explicit_multisample = CheckGLExtension( "GL_NV_explicit_multisample" );
m_GL_NV_fence = CheckGLExtension( "GL_NV_fence" );
m_GL_NV_fill_rectangle = CheckGLExtension( "GL_NV_fill_rectangle" );
m_GL_NV_float_buffer = CheckGLExtension( "GL_NV_float_buffer" );
m_GL_NV_fog_distance = CheckGLExtension( "GL_NV_fog_distance" );
m_GL_NV_fragment_coverage_to_color = CheckGLExtension( "GL_NV_fragment_coverage_to_color" );
m_GL_NV_fragment_program = CheckGLExtension( "GL_NV_fragment_program" );
m_GL_NV_fragment_program2 = CheckGLExtension( "GL_NV_fragment_program2" );
m_GL_NV_fragment_program_option = CheckGLExtension( "GL_NV_fragment_program_option" );
m_GL_NV_fragment_shader_interlock = CheckGLExtension( "GL_NV_fragment_shader_interlock" );
m_GL_NV_framebuffer_mixed_samples = CheckGLExtension( "GL_NV_framebuffer_mixed_samples" );
m_GL_NV_framebuffer_multisample_coverage = CheckGLExtension( "GL_NV_framebuffer_multisample_coverage" );
m_GL_NV_geometry_shader4 = CheckGLExtension( "GL_NV_geometry_shader4" );
m_GL_NV_geometry_shader_passthrough = CheckGLExtension( "GL_NV_geometry_shader_passthrough" );
m_GL_NV_gpu_program4 = CheckGLExtension( "GL_NV_gpu_program4" );
m_GL_NV_gpu_program5 = CheckGLExtension( "GL_NV_gpu_program5" );
m_GL_NV_gpu_program5_mem_extended = CheckGLExtension( "GL_NV_gpu_program5_mem_extended" );
m_GL_NV_gpu_shader5 = CheckGLExtension( "GL_NV_gpu_shader5" );
m_GL_NV_half_float = CheckGLExtension( "GL_NV_half_float" );
m_GL_NV_internalformat_sample_query = CheckGLExtension( "GL_NV_internalformat_sample_query" );
m_GL_NV_light_max_exponent = CheckGLExtension( "GL_NV_light_max_exponent" );
m_GL_NV_multisample_coverage = CheckGLExtension( "GL_NV_multisample_coverage" );
m_GL_NV_multisample_filter_hint = CheckGLExtension( "GL_NV_multisample_filter_hint" );
m_GL_NV_occlusion_query = CheckGLExtension( "GL_NV_occlusion_query" );
m_GL_NV_packed_depth_stencil = CheckGLExtension( "GL_NV_packed_depth_stencil" );
m_GL_NV_parameter_buffer_object = CheckGLExtension( "GL_NV_parameter_buffer_object" );
m_GL_NV_parameter_buffer_object2 = CheckGLExtension( "GL_NV_parameter_buffer_object2" );
m_GL_NV_path_rendering = CheckGLExtension( "GL_NV_path_rendering" );
m_GL_NV_path_rendering_shared_edge = CheckGLExtension( "GL_NV_path_rendering_shared_edge" );
m_GL_NV_pixel_data_range = CheckGLExtension( "GL_NV_pixel_data_range" );
m_GL_NV_point_sprite = CheckGLExtension( "GL_NV_point_sprite" );
m_GL_NV_primitive_restart = CheckGLExtension( "GL_NV_primitive_restart" );
m_GL_NV_register_combiners = CheckGLExtension( "GL_NV_register_combiners" );
m_GL_NV_register_combiners2 = CheckGLExtension( "GL_NV_register_combiners2" );
m_GL_NV_sample_locations = CheckGLExtension( "GL_NV_sample_locations" );
m_GL_NV_sample_mask_override_coverage = CheckGLExtension( "GL_NV_sample_mask_override_coverage" );
m_GL_NV_shader_atomic_counters = CheckGLExtension( "GL_NV_shader_atomic_counters" );
m_GL_NV_shader_atomic_float = CheckGLExtension( "GL_NV_shader_atomic_float" );
m_GL_NV_shader_atomic_fp16_vector = CheckGLExtension( "GL_NV_shader_atomic_fp16_vector" );
m_GL_NV_shader_atomic_int64 = CheckGLExtension( "GL_NV_shader_atomic_int64" );
m_GL_NV_shader_buffer_load = CheckGLExtension( "GL_NV_shader_buffer_load" );
m_GL_NV_shader_storage_buffer_object = CheckGLExtension( "GL_NV_shader_storage_buffer_object" );
m_GL_NV_shader_thread_group = CheckGLExtension( "GL_NV_shader_thread_group" );
m_GL_NV_shader_thread_shuffle = CheckGLExtension( "GL_NV_shader_thread_shuffle" );
m_GL_NV_texgen_reflection = CheckGLExtension( "GL_NV_texgen_reflection" );
m_GL_NV_texture_barrier = CheckGLExtension( "GL_NV_texture_barrier" );
m_GL_NV_texture_compression_vtc = CheckGLExtension( "GL_NV_texture_compression_vtc" );
m_GL_NV_texture_env_combine4 = CheckGLExtension( "GL_NV_texture_env_combine4" );
m_GL_NV_texture_multisample = CheckGLExtension( "GL_NV_texture_multisample" );
m_GL_NV_texture_rectangle = CheckGLExtension( "GL_NV_texture_rectangle" );
m_GL_NV_texture_shader = CheckGLExtension( "GL_NV_texture_shader" );
m_GL_NV_texture_shader2 = CheckGLExtension( "GL_NV_texture_shader2" );
m_GL_NV_texture_shader3 = CheckGLExtension( "GL_NV_texture_shader3" );
m_GL_NV_transform_feedback = CheckGLExtension( "GL_NV_transform_feedback" );
m_GL_NV_transform_feedback2 = CheckGLExtension( "GL_NV_transform_feedback2" );
m_GL_NV_uniform_buffer_unified_memory = CheckGLExtension( "GL_NV_uniform_buffer_unified_memory" );
m_GL_NV_vdpau_interop = CheckGLExtension( "GL_NV_vdpau_interop" );
m_GL_NV_vertex_array_range = CheckGLExtension( "GL_NV_vertex_array_range" );
m_GL_NV_vertex_array_range2 = CheckGLExtension( "GL_NV_vertex_array_range2" );
m_GL_NV_vertex_attrib_integer_64bit = CheckGLExtension( "GL_NV_vertex_attrib_integer_64bit" );
m_GL_NV_vertex_buffer_unified_memory = CheckGLExtension( "GL_NV_vertex_buffer_unified_memory" );
m_GL_NV_vertex_program = CheckGLExtension( "GL_NV_vertex_program" );
m_GL_NV_vertex_program1_1 = CheckGLExtension( "GL_NV_vertex_program1_1" );
m_GL_NV_vertex_program2 = CheckGLExtension( "GL_NV_vertex_program2" );
m_GL_NV_vertex_program2_option = CheckGLExtension( "GL_NV_vertex_program2_option" );
m_GL_NV_vertex_program3 = CheckGLExtension( "GL_NV_vertex_program3" );
m_GL_NV_viewport_array2 = CheckGLExtension( "GL_NV_viewport_array2" );
m_GL_S3_s3tc = CheckGLExtension( "GL_S3_s3tc" );
m_GL_SGIS_generate_mipmap = CheckGLExtension( "GL_SGIS_generate_mipmap" );
m_GL_SGIS_texture_lod = CheckGLExtension( "GL_SGIS_texture_lod" );
m_GL_SGIX_depth_texture = CheckGLExtension( "GL_SGIX_depth_texture" );
m_GL_SGIX_shadow = CheckGLExtension( "GL_SGIX_shadow" );
m_GL_SUN_slice_accum = CheckGLExtension( "GL_SUN_slice_accum" );
}

// --------------------------------------------------------------------------
// Routine to check the presence of a Windows OpenGL extension
//
// Inputs: None
//
// Outputs: None
//
// Results: 1 is returned if the extension exists, 0 otherwise
//
// Effects: None
// --------------------------------------------------------------------------

#ifdef _GLX
int CheckGLXExtension( char *pchname )
{
Display *dptr;
int result = 0;
char *pstr;

dptr = XOpenDisplay(NULL);

if ( dptr )
	{
	pstr = (char *) glXGetClientString( dptr, GLX_EXTENSIONS );

	result = ( strstr( pstr, pchname) != NULL );

	pstr = (char *) glXQueryExtensionsString( dptr, 0 );

	result |= ( strstr( pstr, pchname) != NULL );

	pstr = (char *) glXQueryServerString( dptr, 0, GLX_EXTENSIONS );

	result |= ( strstr( pstr, pchname) != NULL );

	XCloseDisplay(dptr);
	}

return( result );
}

// --------------------------------------------------------------------------
// Routine to check the GLX Extensions
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: Status flags are set according to the OpenGL version present
// --------------------------------------------------------------------------

void CheckGLXExtensions( void )
{
m_GLX_ARB_context_flush_control = CheckGLXExtension( "GLX_ARB_context_flush_control" );
m_GLX_ARB_create_context = CheckGLXExtension( "GLX_ARB_create_context" );
m_GLX_ARB_create_context_profile = CheckGLXExtension( "GLX_ARB_create_context_profile" );
m_GLX_ARB_create_context_robustness = CheckGLXExtension( "GLX_ARB_create_context_robustness" );
m_GLX_ARB_fbconfig_float = CheckGLXExtension( "GLX_ARB_fbconfig_float" );
m_GLX_ARB_multisample = CheckGLXExtension( "GLX_ARB_multisample" );
m_GLX_EXT_buffer_age = CheckGLXExtension( "GLX_EXT_buffer_age" );
m_GLX_EXT_create_context_es2_profile = CheckGLXExtension( "GLX_EXT_create_context_es2_profile" );
m_GLX_EXT_create_context_es_profile = CheckGLXExtension( "GLX_EXT_create_context_es_profile" );
m_GLX_EXT_fbconfig_packed_float = CheckGLXExtension( "GLX_EXT_fbconfig_packed_float" );
m_GLX_EXT_framebuffer_sRGB = CheckGLXExtension( "GLX_EXT_framebuffer_sRGB" );
m_GLX_EXT_import_context = CheckGLXExtension( "GLX_EXT_import_context" );
m_GLX_EXT_stereo_tree = CheckGLXExtension( "GLX_EXT_stereo_tree" );
m_GLX_EXT_swap_control = CheckGLXExtension( "GLX_EXT_swap_control" );
m_GLX_EXT_swap_control_tear = CheckGLXExtension( "GLX_EXT_swap_control_tear" );
m_GLX_EXT_texture_from_pixmap = CheckGLXExtension( "GLX_EXT_texture_from_pixmap" );
m_GLX_EXT_visual_info = CheckGLXExtension( "GLX_EXT_visual_info" );
m_GLX_EXT_visual_rating = CheckGLXExtension( "GLX_EXT_visual_rating" );
m_GLX_NV_copy_buffer = CheckGLXExtension( "GLX_NV_copy_buffer" );
m_GLX_NV_copy_image = CheckGLXExtension( "GLX_NV_copy_image" );
m_GLX_NV_delay_before_swap = CheckGLXExtension( "GLX_NV_delay_before_swap" );
m_GLX_NV_float_buffer = CheckGLXExtension( "GLX_NV_float_buffer" );
m_GLX_NV_multisample_coverage = CheckGLXExtension( "GLX_NV_multisample_coverage" );
m_GLX_NV_present_video = CheckGLXExtension( "GLX_NV_present_video" );
m_GLX_NV_swap_group = CheckGLXExtension( "GLX_NV_swap_group" );
m_GLX_NV_video_capture = CheckGLXExtension( "GLX_NV_video_capture" );
m_GLX_NV_video_out = CheckGLXExtension( "GLX_NV_video_out" );
m_GLX_SGIX_fbconfig = CheckGLXExtension( "GLX_SGIX_fbconfig" );
m_GLX_SGIX_pbuffer = CheckGLXExtension( "GLX_SGIX_pbuffer" );
m_GLX_SGI_swap_control = CheckGLXExtension( "GLX_SGI_swap_control" );
m_GLX_SGI_video_sync = CheckGLXExtension( "GLX_SGI_video_sync" );
}
#endif		// #ifdef _GLX

// --------------------------------------------------------------------------
// Main initialisation routine
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The initialisation routines are called
// --------------------------------------------------------------------------

void ExtensionInit( void )
{
CheckOpenGLVersion();
CheckOpenGLExtensions();

Init_GL_AMD_multi_draw_indirect();
Init_GL_ARB_draw_buffers_blend();
Init_GL_ARB_draw_instanced();
Init_GL_ARB_window_pos();
Init_GL_EXT_draw_buffers2();
Init_GL_EXT_draw_instanced();
Init_GL_EXT_gpu_program_parameters();
Init_GL_EXT_multi_draw_arrays();
Init_GL_NVX_conditional_render();
Init_GL_NV_bindless_multi_draw_indirect();
Init_GL_NV_bindless_multi_draw_indirect_count();
Init_GL_NV_bindless_texture();
Init_GL_NV_copy_image();
Init_GL_NV_draw_texture();
Init_GL_NV_texture_barrier();
Init_GL_NV_vertex_attrib_integer_64bit();

#ifdef _GLX
CheckGLXExtensions();
Init_GLX_NV_copy_buffer();
Init_GLX_NV_copy_image();
Init_GLX_NV_delay_before_swap();
Init_GLX_NV_swap_group();
Init_GLX_SGI_swap_control();
Init_GLX_SGI_video_sync();
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_AMD_multi_draw_indirect
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GL_AMD_multi_draw_indirect( void )
{
#ifdef GL_AMD_multi_draw_indirect
if (!m_GL_AMD_multi_draw_indirect)
	return;

glMultiDrawArraysIndirectAMD = (PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC) GetGLProcAddress( "glMultiDrawArraysIndirectAMD");
glMultiDrawElementsIndirectAMD = (PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC) GetGLProcAddress( "glMultiDrawElementsIndirectAMD");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_ARB_draw_buffers_blend
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GL_ARB_draw_buffers_blend( void )
{
#ifdef GL_ARB_draw_buffers_blend
if (!m_GL_ARB_draw_buffers_blend)
	return;

glBlendEquationiARB = (PFNGLBLENDEQUATIONIARBPROC) GetGLProcAddress( "glBlendEquationiARB");
glBlendEquationSeparateiARB = (PFNGLBLENDEQUATIONSEPARATEIARBPROC) GetGLProcAddress( "glBlendEquationSeparateiARB");
glBlendFunciARB = (PFNGLBLENDFUNCIARBPROC) GetGLProcAddress( "glBlendFunciARB");
glBlendFuncSeparateiARB = (PFNGLBLENDFUNCSEPARATEIARBPROC) GetGLProcAddress( "glBlendFuncSeparateiARB");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_ARB_draw_instanced
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GL_ARB_draw_instanced( void )
{
#ifdef GL_ARB_draw_instanced
if (!m_GL_ARB_draw_instanced)
	return;

glDrawArraysInstancedARB = (PFNGLDRAWARRAYSINSTANCEDARBPROC) GetGLProcAddress( "glDrawArraysInstancedARB");
glDrawElementsInstancedARB = (PFNGLDRAWELEMENTSINSTANCEDARBPROC) GetGLProcAddress( "glDrawElementsInstancedARB");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_ARB_window_pos
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GL_ARB_window_pos( void )
{
#ifdef GL_ARB_window_pos
if (!m_GL_ARB_window_pos)
	return;

glWindowPos2dARB = (PFNGLWINDOWPOS2DARBPROC) GetGLProcAddress( "glWindowPos2dARB");
glWindowPos2dvARB = (PFNGLWINDOWPOS2DVARBPROC) GetGLProcAddress( "glWindowPos2dvARB");
glWindowPos2fARB = (PFNGLWINDOWPOS2FARBPROC) GetGLProcAddress( "glWindowPos2fARB");
glWindowPos2fvARB = (PFNGLWINDOWPOS2FVARBPROC) GetGLProcAddress( "glWindowPos2fvARB");
glWindowPos2iARB = (PFNGLWINDOWPOS2IARBPROC) GetGLProcAddress( "glWindowPos2iARB");
glWindowPos2ivARB = (PFNGLWINDOWPOS2IVARBPROC) GetGLProcAddress( "glWindowPos2ivARB");
glWindowPos2sARB = (PFNGLWINDOWPOS2SARBPROC) GetGLProcAddress( "glWindowPos2sARB");
glWindowPos2svARB = (PFNGLWINDOWPOS2SVARBPROC) GetGLProcAddress( "glWindowPos2svARB");
glWindowPos3dARB = (PFNGLWINDOWPOS3DARBPROC) GetGLProcAddress( "glWindowPos3dARB");
glWindowPos3dvARB = (PFNGLWINDOWPOS3DVARBPROC) GetGLProcAddress( "glWindowPos3dvARB");
glWindowPos3fARB = (PFNGLWINDOWPOS3FARBPROC) GetGLProcAddress( "glWindowPos3fARB");
glWindowPos3fvARB = (PFNGLWINDOWPOS3FVARBPROC) GetGLProcAddress( "glWindowPos3fvARB");
glWindowPos3iARB = (PFNGLWINDOWPOS3IARBPROC) GetGLProcAddress( "glWindowPos3iARB");
glWindowPos3ivARB = (PFNGLWINDOWPOS3IVARBPROC) GetGLProcAddress( "glWindowPos3ivARB");
glWindowPos3sARB = (PFNGLWINDOWPOS3SARBPROC) GetGLProcAddress( "glWindowPos3sARB");
glWindowPos3svARB = (PFNGLWINDOWPOS3SVARBPROC) GetGLProcAddress( "glWindowPos3svARB");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_EXT_draw_buffers2
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GL_EXT_draw_buffers2( void )
{
#ifdef GL_EXT_draw_buffers2
if (!m_GL_EXT_draw_buffers2)
	return;

glColorMaskIndexedEXT = (PFNGLCOLORMASKINDEXEDEXTPROC) GetGLProcAddress( "glColorMaskIndexedEXT");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_EXT_draw_instanced
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GL_EXT_draw_instanced( void )
{
#ifdef GL_EXT_draw_instanced
if (!m_GL_EXT_draw_instanced)
	return;

glDrawArraysInstancedEXT = (PFNGLDRAWARRAYSINSTANCEDEXTPROC) GetGLProcAddress( "glDrawArraysInstancedEXT");
glDrawElementsInstancedEXT = (PFNGLDRAWELEMENTSINSTANCEDEXTPROC) GetGLProcAddress( "glDrawElementsInstancedEXT");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_EXT_gpu_program_parameters
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GL_EXT_gpu_program_parameters( void )
{
#ifdef GL_EXT_gpu_program_parameters
if (!m_GL_EXT_gpu_program_parameters)
	return;

glProgramEnvParameters4fvEXT = (PFNGLPROGRAMENVPARAMETERS4FVEXTPROC) GetGLProcAddress( "glProgramEnvParameters4fvEXT");
glProgramLocalParameters4fvEXT = (PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC) GetGLProcAddress( "glProgramLocalParameters4fvEXT");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_EXT_multi_draw_arrays
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GL_EXT_multi_draw_arrays( void )
{
#ifdef GL_EXT_multi_draw_arrays
if (!m_GL_EXT_multi_draw_arrays)
	return;

glMultiDrawArraysEXT = (PFNGLMULTIDRAWARRAYSEXTPROC) GetGLProcAddress( "glMultiDrawArraysEXT");
glMultiDrawElementsEXT = (PFNGLMULTIDRAWELEMENTSEXTPROC) GetGLProcAddress( "glMultiDrawElementsEXT");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_NVX_conditional_render
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GL_NVX_conditional_render( void )
{
#ifdef GL_NVX_conditional_render
if (!m_GL_NVX_conditional_render)
	return;

glBeginConditionalRenderNVX = (PFNGLBEGINCONDITIONALRENDERNVXPROC) GetGLProcAddress( "glBeginConditionalRenderNVX");
glEndConditionalRenderNVX = (PFNGLENDCONDITIONALRENDERNVXPROC) GetGLProcAddress( "glEndConditionalRenderNVX");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_NV_bindless_multi_draw_indirect
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GL_NV_bindless_multi_draw_indirect( void )
{
#ifdef GL_NV_bindless_multi_draw_indirect
if (!m_GL_NV_bindless_multi_draw_indirect)
	return;

glMultiDrawArraysIndirectBindlessNV = (PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC) GetGLProcAddress( "glMultiDrawArraysIndirectBindlessNV");
glMultiDrawElementsIndirectBindlessNV = (PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC) GetGLProcAddress( "glMultiDrawElementsIndirectBindlessNV");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_NV_bindless_multi_draw_indirect_count
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GL_NV_bindless_multi_draw_indirect_count( void )
{
#ifdef GL_NV_bindless_multi_draw_indirect_count
if (!m_GL_NV_bindless_multi_draw_indirect_count)
	return;

glMultiDrawArraysIndirectBindlessCountNV = (PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC) GetGLProcAddress( "glMultiDrawArraysIndirectBindlessCountNV");
glMultiDrawElementsIndirectBindlessCountNV = (PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC) GetGLProcAddress( "glMultiDrawElementsIndirectBindlessCountNV");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_NV_bindless_texture
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GL_NV_bindless_texture( void )
{
#ifdef GL_NV_bindless_texture
if (!m_GL_NV_bindless_texture)
	return;

glGetTextureHandleNV = (PFNGLGETTEXTUREHANDLENVPROC) GetGLProcAddress( "glGetTextureHandleNV");
glGetTextureSamplerHandleNV = (PFNGLGETTEXTURESAMPLERHANDLENVPROC) GetGLProcAddress( "glGetTextureSamplerHandleNV");
glMakeTextureHandleResidentNV = (PFNGLMAKETEXTUREHANDLERESIDENTNVPROC) GetGLProcAddress( "glMakeTextureHandleResidentNV");
glMakeTextureHandleNonResidentNV = (PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC) GetGLProcAddress( "glMakeTextureHandleNonResidentNV");
glGetImageHandleNV = (PFNGLGETIMAGEHANDLENVPROC) GetGLProcAddress( "glGetImageHandleNV");
glMakeImageHandleResidentNV = (PFNGLMAKEIMAGEHANDLERESIDENTNVPROC) GetGLProcAddress( "glMakeImageHandleResidentNV");
glMakeImageHandleNonResidentNV = (PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC) GetGLProcAddress( "glMakeImageHandleNonResidentNV");
glUniformHandleui64NV = (PFNGLUNIFORMHANDLEUI64NVPROC) GetGLProcAddress( "glUniformHandleui64NV");
glUniformHandleui64vNV = (PFNGLUNIFORMHANDLEUI64VNVPROC) GetGLProcAddress( "glUniformHandleui64vNV");
glProgramUniformHandleui64NV = (PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC) GetGLProcAddress( "glProgramUniformHandleui64NV");
glProgramUniformHandleui64vNV = (PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC) GetGLProcAddress( "glProgramUniformHandleui64vNV");
glIsTextureHandleResidentNV = (PFNGLISTEXTUREHANDLERESIDENTNVPROC) GetGLProcAddress( "glIsTextureHandleResidentNV");
glIsImageHandleResidentNV = (PFNGLISIMAGEHANDLERESIDENTNVPROC) GetGLProcAddress( "glIsImageHandleResidentNV");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_NV_copy_image
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GL_NV_copy_image( void )
{
#ifdef GL_NV_copy_image
if (!m_GL_NV_copy_image)
	return;

glCopyImageSubDataNV = (PFNGLCOPYIMAGESUBDATANVPROC) GetGLProcAddress( "glCopyImageSubDataNV");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_NV_draw_texture
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GL_NV_draw_texture( void )
{
#ifdef GL_NV_draw_texture
if (!m_GL_NV_draw_texture)
	return;

glDrawTextureNV = (PFNGLDRAWTEXTURENVPROC) GetGLProcAddress( "glDrawTextureNV");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_NV_texture_barrier
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GL_NV_texture_barrier( void )
{
#ifdef GL_NV_texture_barrier
if (!m_GL_NV_texture_barrier)
	return;

glTextureBarrierNV = (PFNGLTEXTUREBARRIERNVPROC) GetGLProcAddress( "glTextureBarrierNV");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_NV_vertex_attrib_integer_64bit
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GL_NV_vertex_attrib_integer_64bit( void )
{
#ifdef GL_NV_vertex_attrib_integer_64bit
if (!m_GL_NV_vertex_attrib_integer_64bit)
	return;

glVertexAttribL1i64NV = (PFNGLVERTEXATTRIBL1I64NVPROC) GetGLProcAddress( "glVertexAttribL1i64NV");
glVertexAttribL2i64NV = (PFNGLVERTEXATTRIBL2I64NVPROC) GetGLProcAddress( "glVertexAttribL2i64NV");
glVertexAttribL3i64NV = (PFNGLVERTEXATTRIBL3I64NVPROC) GetGLProcAddress( "glVertexAttribL3i64NV");
glVertexAttribL4i64NV = (PFNGLVERTEXATTRIBL4I64NVPROC) GetGLProcAddress( "glVertexAttribL4i64NV");
glVertexAttribL1i64vNV = (PFNGLVERTEXATTRIBL1I64VNVPROC) GetGLProcAddress( "glVertexAttribL1i64vNV");
glVertexAttribL2i64vNV = (PFNGLVERTEXATTRIBL2I64VNVPROC) GetGLProcAddress( "glVertexAttribL2i64vNV");
glVertexAttribL3i64vNV = (PFNGLVERTEXATTRIBL3I64VNVPROC) GetGLProcAddress( "glVertexAttribL3i64vNV");
glVertexAttribL4i64vNV = (PFNGLVERTEXATTRIBL4I64VNVPROC) GetGLProcAddress( "glVertexAttribL4i64vNV");
glVertexAttribL1ui64NV = (PFNGLVERTEXATTRIBL1UI64NVPROC) GetGLProcAddress( "glVertexAttribL1ui64NV");
glVertexAttribL2ui64NV = (PFNGLVERTEXATTRIBL2UI64NVPROC) GetGLProcAddress( "glVertexAttribL2ui64NV");
glVertexAttribL3ui64NV = (PFNGLVERTEXATTRIBL3UI64NVPROC) GetGLProcAddress( "glVertexAttribL3ui64NV");
glVertexAttribL4ui64NV = (PFNGLVERTEXATTRIBL4UI64NVPROC) GetGLProcAddress( "glVertexAttribL4ui64NV");
glVertexAttribL1ui64vNV = (PFNGLVERTEXATTRIBL1UI64VNVPROC) GetGLProcAddress( "glVertexAttribL1ui64vNV");
glVertexAttribL2ui64vNV = (PFNGLVERTEXATTRIBL2UI64VNVPROC) GetGLProcAddress( "glVertexAttribL2ui64vNV");
glVertexAttribL3ui64vNV = (PFNGLVERTEXATTRIBL3UI64VNVPROC) GetGLProcAddress( "glVertexAttribL3ui64vNV");
glVertexAttribL4ui64vNV = (PFNGLVERTEXATTRIBL4UI64VNVPROC) GetGLProcAddress( "glVertexAttribL4ui64vNV");
glGetVertexAttribLi64vNV = (PFNGLGETVERTEXATTRIBLI64VNVPROC) GetGLProcAddress( "glGetVertexAttribLi64vNV");
glGetVertexAttribLui64vNV = (PFNGLGETVERTEXATTRIBLUI64VNVPROC) GetGLProcAddress( "glGetVertexAttribLui64vNV");
glVertexAttribLFormatNV = (PFNGLVERTEXATTRIBLFORMATNVPROC) GetGLProcAddress( "glVertexAttribLFormatNV");
#endif
}

#ifdef _GLX
// --------------------------------------------------------------------------
// Initialise extension GLX_NV_copy_buffer
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GLX_NV_copy_buffer( void )
{
#ifdef GLX_NV_copy_buffer
if (!m_GLX_NV_copy_buffer)
	return;

glXCopyBufferSubDataNV = (PFNGLXCOPYBUFFERSUBDATANVPROC) GetGLProcAddress( "glXCopyBufferSubDataNV");
glXNamedCopyBufferSubDataNV = (PFNGLXNAMEDCOPYBUFFERSUBDATANVPROC) GetGLProcAddress( "glXNamedCopyBufferSubDataNV");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GLX_NV_copy_image
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GLX_NV_copy_image( void )
{
#ifdef GLX_NV_copy_image
if (!m_GLX_NV_copy_image)
	return;

glXCopyImageSubDataNV = (PFNGLXCOPYIMAGESUBDATANVPROC) GetGLProcAddress( "glXCopyImageSubDataNV");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GLX_NV_delay_before_swap
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GLX_NV_delay_before_swap( void )
{
#ifdef GLX_NV_delay_before_swap
if (!m_GLX_NV_delay_before_swap)
	return;

glXDelayBeforeSwapNV = (PFNGLXDELAYBEFORESWAPNVPROC) GetGLProcAddress( "glXDelayBeforeSwapNV");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GLX_NV_swap_group
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GLX_NV_swap_group( void )
{
#ifdef GLX_NV_swap_group
if (!m_GLX_NV_swap_group)
	return;

glXJoinSwapGroupNV = (PFNGLXJOINSWAPGROUPNVPROC) GetGLProcAddress( "glXJoinSwapGroupNV");
glXBindSwapBarrierNV = (PFNGLXBINDSWAPBARRIERNVPROC) GetGLProcAddress( "glXBindSwapBarrierNV");
glXQuerySwapGroupNV = (PFNGLXQUERYSWAPGROUPNVPROC) GetGLProcAddress( "glXQuerySwapGroupNV");
glXQueryMaxSwapGroupsNV = (PFNGLXQUERYMAXSWAPGROUPSNVPROC) GetGLProcAddress( "glXQueryMaxSwapGroupsNV");
glXQueryFrameCountNV = (PFNGLXQUERYFRAMECOUNTNVPROC) GetGLProcAddress( "glXQueryFrameCountNV");
glXResetFrameCountNV = (PFNGLXRESETFRAMECOUNTNVPROC) GetGLProcAddress( "glXResetFrameCountNV");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GLX_SGI_swap_control
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GLX_SGI_swap_control( void )
{
#ifdef GLX_SGI_swap_control
if (!m_GLX_SGI_swap_control)
	return;

glXSwapIntervalSGI = (PFNGLXSWAPINTERVALSGIPROC) GetGLProcAddress( "glXSwapIntervalSGI");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GLX_SGI_video_sync
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void Init_GLX_SGI_video_sync( void )
{
#ifdef GLX_SGI_video_sync
if (!m_GLX_SGI_video_sync)
	return;

glXGetVideoSyncSGI = (PFNGLXGETVIDEOSYNCSGIPROC) GetGLProcAddress( "glXGetVideoSyncSGI");
glXWaitVideoSyncSGI = (PFNGLXWAITVIDEOSYNCSGIPROC) GetGLProcAddress( "glXWaitVideoSyncSGI");
#endif
}

#endif // _GLX
