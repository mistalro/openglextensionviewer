// --------------------------------------------------------------------------
// Header file for the extension manager
//
// Stored in file extmanager.cpp
//
// File:   extmanager.h
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

#ifndef __EXTMANAGER__
#define __EXTMANAGER__

// Extension presence flags

extern int m_OpenGL12;
extern int m_OpenGL13;
extern int m_OpenGL14;
extern int m_OpenGL15;
extern int m_OpenGL20;
extern int m_OpenGL21;
extern int m_OpenGL30;
extern int m_OpenGL31;
extern int m_OpenGL32;
extern int m_OpenGL33;
extern int m_OpenGL40;
extern int m_OpenGL41;
extern int m_OpenGL42;
extern int m_OpenGL43;
extern int m_OpenGL44;
extern int m_OpenGL45;
extern int m_OpenGL10;
extern int m_OpenGL11;

extern int m_GL_AMD_multi_draw_indirect;
extern int m_GL_AMD_seamless_cubemap_per_texture;
extern int m_GL_AMD_vertex_shader_layer;
extern int m_GL_AMD_vertex_shader_viewport_index;
extern int m_GL_ARB_ES2_compatibility;
extern int m_GL_ARB_ES3_1_compatibility;
extern int m_GL_ARB_ES3_compatibility;
extern int m_GL_ARB_arrays_of_arrays;
extern int m_GL_ARB_base_instance;
extern int m_GL_ARB_bindless_texture;
extern int m_GL_ARB_blend_func_extended;
extern int m_GL_ARB_buffer_storage;
extern int m_GL_ARB_clear_buffer_object;
extern int m_GL_ARB_clear_texture;
extern int m_GL_ARB_clip_control;
extern int m_GL_ARB_color_buffer_float;
extern int m_GL_ARB_compatibility;
extern int m_GL_ARB_compressed_texture_pixel_storage;
extern int m_GL_ARB_compute_shader;
extern int m_GL_ARB_compute_variable_group_size;
extern int m_GL_ARB_conditional_render_inverted;
extern int m_GL_ARB_conservative_depth;
extern int m_GL_ARB_copy_buffer;
extern int m_GL_ARB_copy_image;
extern int m_GL_ARB_cull_distance;
extern int m_GL_ARB_debug_output;
extern int m_GL_ARB_depth_buffer_float;
extern int m_GL_ARB_depth_clamp;
extern int m_GL_ARB_depth_texture;
extern int m_GL_ARB_derivative_control;
extern int m_GL_ARB_direct_state_access;
extern int m_GL_ARB_draw_buffers;
extern int m_GL_ARB_draw_buffers_blend;
extern int m_GL_ARB_draw_elements_base_vertex;
extern int m_GL_ARB_draw_indirect;
extern int m_GL_ARB_draw_instanced;
extern int m_GL_ARB_enhanced_layouts;
extern int m_GL_ARB_explicit_attrib_location;
extern int m_GL_ARB_explicit_uniform_location;
extern int m_GL_ARB_fragment_coord_conventions;
extern int m_GL_ARB_fragment_layer_viewport;
extern int m_GL_ARB_fragment_program;
extern int m_GL_ARB_fragment_program_shadow;
extern int m_GL_ARB_fragment_shader;
extern int m_GL_ARB_framebuffer_no_attachments;
extern int m_GL_ARB_framebuffer_object;
extern int m_GL_ARB_framebuffer_sRGB;
extern int m_GL_ARB_geometry_shader4;
extern int m_GL_ARB_get_program_binary;
extern int m_GL_ARB_get_texture_sub_image;
extern int m_GL_ARB_gpu_shader5;
extern int m_GL_ARB_gpu_shader_fp64;
extern int m_GL_ARB_half_float_pixel;
extern int m_GL_ARB_half_float_vertex;
extern int m_GL_ARB_imaging;
extern int m_GL_ARB_indirect_parameters;
extern int m_GL_ARB_instanced_arrays;
extern int m_GL_ARB_internalformat_query;
extern int m_GL_ARB_internalformat_query2;
extern int m_GL_ARB_invalidate_subdata;
extern int m_GL_ARB_map_buffer_alignment;
extern int m_GL_ARB_map_buffer_range;
extern int m_GL_ARB_multi_bind;
extern int m_GL_ARB_multi_draw_indirect;
extern int m_GL_ARB_multisample;
extern int m_GL_ARB_multitexture;
extern int m_GL_ARB_occlusion_query;
extern int m_GL_ARB_occlusion_query2;
extern int m_GL_ARB_pipeline_statistics_query;
extern int m_GL_ARB_pixel_buffer_object;
extern int m_GL_ARB_point_parameters;
extern int m_GL_ARB_point_sprite;
extern int m_GL_ARB_program_interface_query;
extern int m_GL_ARB_provoking_vertex;
extern int m_GL_ARB_query_buffer_object;
extern int m_GL_ARB_robust_buffer_access_behavior;
extern int m_GL_ARB_robustness;
extern int m_GL_ARB_sample_shading;
extern int m_GL_ARB_sampler_objects;
extern int m_GL_ARB_seamless_cube_map;
extern int m_GL_ARB_seamless_cubemap_per_texture;
extern int m_GL_ARB_separate_shader_objects;
extern int m_GL_ARB_shader_atomic_counters;
extern int m_GL_ARB_shader_bit_encoding;
extern int m_GL_ARB_shader_draw_parameters;
extern int m_GL_ARB_shader_group_vote;
extern int m_GL_ARB_shader_image_load_store;
extern int m_GL_ARB_shader_image_size;
extern int m_GL_ARB_shader_objects;
extern int m_GL_ARB_shader_precision;
extern int m_GL_ARB_shader_storage_buffer_object;
extern int m_GL_ARB_shader_subroutine;
extern int m_GL_ARB_shader_texture_image_samples;
extern int m_GL_ARB_shader_texture_lod;
extern int m_GL_ARB_shading_language_100;
extern int m_GL_ARB_shading_language_420pack;
extern int m_GL_ARB_shading_language_include;
extern int m_GL_ARB_shading_language_packing;
extern int m_GL_ARB_shadow;
extern int m_GL_ARB_sparse_buffer;
extern int m_GL_ARB_sparse_texture;
extern int m_GL_ARB_stencil_texturing;
extern int m_GL_ARB_sync;
extern int m_GL_ARB_tessellation_shader;
extern int m_GL_ARB_texture_barrier;
extern int m_GL_ARB_texture_border_clamp;
extern int m_GL_ARB_texture_buffer_object;
extern int m_GL_ARB_texture_buffer_object_rgb32;
extern int m_GL_ARB_texture_buffer_range;
extern int m_GL_ARB_texture_compression;
extern int m_GL_ARB_texture_compression_bptc;
extern int m_GL_ARB_texture_compression_rgtc;
extern int m_GL_ARB_texture_cube_map;
extern int m_GL_ARB_texture_cube_map_array;
extern int m_GL_ARB_texture_env_add;
extern int m_GL_ARB_texture_env_combine;
extern int m_GL_ARB_texture_env_crossbar;
extern int m_GL_ARB_texture_env_dot3;
extern int m_GL_ARB_texture_float;
extern int m_GL_ARB_texture_gather;
extern int m_GL_ARB_texture_mirror_clamp_to_edge;
extern int m_GL_ARB_texture_mirrored_repeat;
extern int m_GL_ARB_texture_multisample;
extern int m_GL_ARB_texture_non_power_of_two;
extern int m_GL_ARB_texture_query_levels;
extern int m_GL_ARB_texture_query_lod;
extern int m_GL_ARB_texture_rectangle;
extern int m_GL_ARB_texture_rg;
extern int m_GL_ARB_texture_rgb10_a2ui;
extern int m_GL_ARB_texture_stencil8;
extern int m_GL_ARB_texture_storage;
extern int m_GL_ARB_texture_storage_multisample;
extern int m_GL_ARB_texture_swizzle;
extern int m_GL_ARB_texture_view;
extern int m_GL_ARB_timer_query;
extern int m_GL_ARB_transform_feedback2;
extern int m_GL_ARB_transform_feedback3;
extern int m_GL_ARB_transform_feedback_instanced;
extern int m_GL_ARB_transform_feedback_overflow_query;
extern int m_GL_ARB_transpose_matrix;
extern int m_GL_ARB_uniform_buffer_object;
extern int m_GL_ARB_vertex_array_bgra;
extern int m_GL_ARB_vertex_array_object;
extern int m_GL_ARB_vertex_attrib_64bit;
extern int m_GL_ARB_vertex_attrib_binding;
extern int m_GL_ARB_vertex_buffer_object;
extern int m_GL_ARB_vertex_program;
extern int m_GL_ARB_vertex_shader;
extern int m_GL_ARB_vertex_type_10f_11f_11f_rev;
extern int m_GL_ARB_vertex_type_2_10_10_10_rev;
extern int m_GL_ARB_viewport_array;
extern int m_GL_ARB_window_pos;
extern int m_GL_ATI_draw_buffers;
extern int m_GL_ATI_texture_float;
extern int m_GL_ATI_texture_mirror_once;
extern int m_GL_EXT_abgr;
extern int m_GL_EXT_bgra;
extern int m_GL_EXT_bindable_uniform;
extern int m_GL_EXT_blend_color;
extern int m_GL_EXT_blend_equation_separate;
extern int m_GL_EXT_blend_func_separate;
extern int m_GL_EXT_blend_minmax;
extern int m_GL_EXT_blend_subtract;
extern int m_GL_EXT_compiled_vertex_array;
extern int m_GL_EXT_depth_bounds_test;
extern int m_GL_EXT_direct_state_access;
extern int m_GL_EXT_draw_buffers2;
extern int m_GL_EXT_draw_instanced;
extern int m_GL_EXT_draw_range_elements;
extern int m_GL_EXT_fog_coord;
extern int m_GL_EXT_framebuffer_blit;
extern int m_GL_EXT_framebuffer_multisample;
extern int m_GL_EXT_framebuffer_multisample_blit_scaled;
extern int m_GL_EXT_framebuffer_object;
extern int m_GL_EXT_framebuffer_sRGB;
extern int m_GL_EXT_geometry_shader4;
extern int m_GL_EXT_gpu_program_parameters;
extern int m_GL_EXT_gpu_shader4;
extern int m_GL_EXT_multi_draw_arrays;
extern int m_GL_EXT_packed_depth_stencil;
extern int m_GL_EXT_packed_float;
extern int m_GL_EXT_packed_pixels;
extern int m_GL_EXT_pixel_buffer_object;
extern int m_GL_EXT_point_parameters;
extern int m_GL_EXT_polygon_offset_clamp;
extern int m_GL_EXT_post_depth_coverage;
extern int m_GL_EXT_provoking_vertex;
extern int m_GL_EXT_raster_multisample;
extern int m_GL_EXT_rescale_normal;
extern int m_GL_EXT_secondary_color;
extern int m_GL_EXT_separate_shader_objects;
extern int m_GL_EXT_separate_specular_color;
extern int m_GL_EXT_shader_image_load_formatted;
extern int m_GL_EXT_shader_image_load_store;
extern int m_GL_EXT_shader_integer_mix;
extern int m_GL_EXT_shadow_funcs;
extern int m_GL_EXT_sparse_texture2;
extern int m_GL_EXT_stencil_two_side;
extern int m_GL_EXT_stencil_wrap;
extern int m_GL_EXT_texture3D;
extern int m_GL_EXT_texture_array;
extern int m_GL_EXT_texture_buffer_object;
extern int m_GL_EXT_texture_compression_latc;
extern int m_GL_EXT_texture_compression_rgtc;
extern int m_GL_EXT_texture_compression_s3tc;
extern int m_GL_EXT_texture_cube_map;
extern int m_GL_EXT_texture_env_add;
extern int m_GL_EXT_texture_env_combine;
extern int m_GL_EXT_texture_env_dot3;
extern int m_GL_EXT_texture_filter_anisotropic;
extern int m_GL_EXT_texture_filter_minmax;
extern int m_GL_EXT_texture_integer;
extern int m_GL_EXT_texture_lod_bias;
extern int m_GL_EXT_texture_mirror_clamp;
extern int m_GL_EXT_texture_object;
extern int m_GL_EXT_texture_sRGB;
extern int m_GL_EXT_texture_sRGB_decode;
extern int m_GL_EXT_texture_shared_exponent;
extern int m_GL_EXT_texture_swizzle;
extern int m_GL_EXT_timer_query;
extern int m_GL_EXT_vertex_array;
extern int m_GL_EXT_vertex_array_bgra;
extern int m_GL_EXT_vertex_attrib_64bit;
extern int m_GL_EXT_x11_sync_object;
extern int m_GL_IBM_rasterpos_clip;
extern int m_GL_IBM_texture_mirrored_repeat;
extern int m_GL_KHR_blend_equation_advanced;
extern int m_GL_KHR_blend_equation_advanced_coherent;
extern int m_GL_KHR_context_flush_control;
extern int m_GL_KHR_debug;
extern int m_GL_KHR_robust_buffer_access_behavior;
extern int m_GL_KHR_robustness;
extern int m_GL_NVX_conditional_render;
extern int m_GL_NVX_gpu_memory_info;
extern int m_GL_NV_bindless_multi_draw_indirect;
extern int m_GL_NV_bindless_multi_draw_indirect_count;
extern int m_GL_NV_bindless_texture;
extern int m_GL_NV_blend_equation_advanced;
extern int m_GL_NV_blend_equation_advanced_coherent;
extern int m_GL_NV_blend_square;
extern int m_GL_NV_command_list;
extern int m_GL_NV_compute_program5;
extern int m_GL_NV_conditional_render;
extern int m_GL_NV_conservative_raster;
extern int m_GL_NV_conservative_raster_dilate;
extern int m_GL_NV_copy_depth_to_color;
extern int m_GL_NV_copy_image;
extern int m_GL_NV_depth_buffer_float;
extern int m_GL_NV_depth_clamp;
extern int m_GL_NV_draw_texture;
extern int m_GL_NV_explicit_multisample;
extern int m_GL_NV_fence;
extern int m_GL_NV_fill_rectangle;
extern int m_GL_NV_float_buffer;
extern int m_GL_NV_fog_distance;
extern int m_GL_NV_fragment_coverage_to_color;
extern int m_GL_NV_fragment_program;
extern int m_GL_NV_fragment_program2;
extern int m_GL_NV_fragment_program_option;
extern int m_GL_NV_fragment_shader_interlock;
extern int m_GL_NV_framebuffer_mixed_samples;
extern int m_GL_NV_framebuffer_multisample_coverage;
extern int m_GL_NV_geometry_shader4;
extern int m_GL_NV_geometry_shader_passthrough;
extern int m_GL_NV_gpu_program4;
extern int m_GL_NV_gpu_program5;
extern int m_GL_NV_gpu_program5_mem_extended;
extern int m_GL_NV_gpu_shader5;
extern int m_GL_NV_half_float;
extern int m_GL_NV_internalformat_sample_query;
extern int m_GL_NV_light_max_exponent;
extern int m_GL_NV_multisample_coverage;
extern int m_GL_NV_multisample_filter_hint;
extern int m_GL_NV_occlusion_query;
extern int m_GL_NV_packed_depth_stencil;
extern int m_GL_NV_parameter_buffer_object;
extern int m_GL_NV_parameter_buffer_object2;
extern int m_GL_NV_path_rendering;
extern int m_GL_NV_path_rendering_shared_edge;
extern int m_GL_NV_pixel_data_range;
extern int m_GL_NV_point_sprite;
extern int m_GL_NV_primitive_restart;
extern int m_GL_NV_register_combiners;
extern int m_GL_NV_register_combiners2;
extern int m_GL_NV_sample_locations;
extern int m_GL_NV_sample_mask_override_coverage;
extern int m_GL_NV_shader_atomic_counters;
extern int m_GL_NV_shader_atomic_float;
extern int m_GL_NV_shader_atomic_fp16_vector;
extern int m_GL_NV_shader_atomic_int64;
extern int m_GL_NV_shader_buffer_load;
extern int m_GL_NV_shader_storage_buffer_object;
extern int m_GL_NV_shader_thread_group;
extern int m_GL_NV_shader_thread_shuffle;
extern int m_GL_NV_texgen_reflection;
extern int m_GL_NV_texture_barrier;
extern int m_GL_NV_texture_compression_vtc;
extern int m_GL_NV_texture_env_combine4;
extern int m_GL_NV_texture_multisample;
extern int m_GL_NV_texture_rectangle;
extern int m_GL_NV_texture_shader;
extern int m_GL_NV_texture_shader2;
extern int m_GL_NV_texture_shader3;
extern int m_GL_NV_transform_feedback;
extern int m_GL_NV_transform_feedback2;
extern int m_GL_NV_uniform_buffer_unified_memory;
extern int m_GL_NV_vdpau_interop;
extern int m_GL_NV_vertex_array_range;
extern int m_GL_NV_vertex_array_range2;
extern int m_GL_NV_vertex_attrib_integer_64bit;
extern int m_GL_NV_vertex_buffer_unified_memory;
extern int m_GL_NV_vertex_program;
extern int m_GL_NV_vertex_program1_1;
extern int m_GL_NV_vertex_program2;
extern int m_GL_NV_vertex_program2_option;
extern int m_GL_NV_vertex_program3;
extern int m_GL_NV_viewport_array2;
extern int m_GL_S3_s3tc;
extern int m_GL_SGIS_generate_mipmap;
extern int m_GL_SGIS_texture_lod;
extern int m_GL_SGIX_depth_texture;
extern int m_GL_SGIX_shadow;
extern int m_GL_SUN_slice_accum;

#ifdef _GLX

extern int m_GLX_ARB_context_flush_control;
extern int m_GLX_ARB_create_context;
extern int m_GLX_ARB_create_context_profile;
extern int m_GLX_ARB_create_context_robustness;
extern int m_GLX_ARB_fbconfig_float;
extern int m_GLX_ARB_multisample;
extern int m_GLX_EXT_buffer_age;
extern int m_GLX_EXT_create_context_es2_profile;
extern int m_GLX_EXT_create_context_es_profile;
extern int m_GLX_EXT_fbconfig_packed_float;
extern int m_GLX_EXT_framebuffer_sRGB;
extern int m_GLX_EXT_import_context;
extern int m_GLX_EXT_stereo_tree;
extern int m_GLX_EXT_swap_control;
extern int m_GLX_EXT_swap_control_tear;
extern int m_GLX_EXT_texture_from_pixmap;
extern int m_GLX_EXT_visual_info;
extern int m_GLX_EXT_visual_rating;
extern int m_GLX_NV_copy_buffer;
extern int m_GLX_NV_copy_image;
extern int m_GLX_NV_delay_before_swap;
extern int m_GLX_NV_float_buffer;
extern int m_GLX_NV_multisample_coverage;
extern int m_GLX_NV_present_video;
extern int m_GLX_NV_swap_group;
extern int m_GLX_NV_video_capture;
extern int m_GLX_NV_video_out;
extern int m_GLX_SGIX_fbconfig;
extern int m_GLX_SGIX_pbuffer;
extern int m_GLX_SGI_swap_control;
extern int m_GLX_SGI_video_sync;

#endif		// _GLX

//
// ----- GL extensions --------
//

#ifdef NONO
#ifdef GL_AMD_multi_draw_indirect
extern PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC glMultiDrawArraysIndirectAMD;
extern PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC glMultiDrawElementsIndirectAMD;
#endif		// GL_AMD_multi_draw_indirect

#ifdef GL_ARB_draw_buffers_blend
extern PFNGLBLENDEQUATIONIARBPROC glBlendEquationiARB;
extern PFNGLBLENDEQUATIONSEPARATEIARBPROC glBlendEquationSeparateiARB;
extern PFNGLBLENDFUNCIARBPROC glBlendFunciARB;
extern PFNGLBLENDFUNCSEPARATEIARBPROC glBlendFuncSeparateiARB;
#endif		// GL_ARB_draw_buffers_blend

#ifdef GL_ARB_draw_instanced
extern PFNGLDRAWARRAYSINSTANCEDARBPROC glDrawArraysInstancedARB;
extern PFNGLDRAWELEMENTSINSTANCEDARBPROC glDrawElementsInstancedARB;
#endif		// GL_ARB_draw_instanced

#ifdef GL_ARB_window_pos
extern PFNGLWINDOWPOS2DARBPROC glWindowPos2dARB;
extern PFNGLWINDOWPOS2DVARBPROC glWindowPos2dvARB;
extern PFNGLWINDOWPOS2FARBPROC glWindowPos2fARB;
extern PFNGLWINDOWPOS2FVARBPROC glWindowPos2fvARB;
extern PFNGLWINDOWPOS2IARBPROC glWindowPos2iARB;
extern PFNGLWINDOWPOS2IVARBPROC glWindowPos2ivARB;
extern PFNGLWINDOWPOS2SARBPROC glWindowPos2sARB;
extern PFNGLWINDOWPOS2SVARBPROC glWindowPos2svARB;
extern PFNGLWINDOWPOS3DARBPROC glWindowPos3dARB;
extern PFNGLWINDOWPOS3DVARBPROC glWindowPos3dvARB;
extern PFNGLWINDOWPOS3FARBPROC glWindowPos3fARB;
extern PFNGLWINDOWPOS3FVARBPROC glWindowPos3fvARB;
extern PFNGLWINDOWPOS3IARBPROC glWindowPos3iARB;
extern PFNGLWINDOWPOS3IVARBPROC glWindowPos3ivARB;
extern PFNGLWINDOWPOS3SARBPROC glWindowPos3sARB;
extern PFNGLWINDOWPOS3SVARBPROC glWindowPos3svARB;
#endif		// GL_ARB_window_pos

#ifdef GL_EXT_draw_buffers2
extern PFNGLCOLORMASKINDEXEDEXTPROC glColorMaskIndexedEXT;
#endif		// GL_EXT_draw_buffers2

#ifdef GL_EXT_draw_instanced
extern PFNGLDRAWARRAYSINSTANCEDEXTPROC glDrawArraysInstancedEXT;
extern PFNGLDRAWELEMENTSINSTANCEDEXTPROC glDrawElementsInstancedEXT;
#endif		// GL_EXT_draw_instanced

#ifdef GL_EXT_gpu_program_parameters
extern PFNGLPROGRAMENVPARAMETERS4FVEXTPROC glProgramEnvParameters4fvEXT;
extern PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC glProgramLocalParameters4fvEXT;
#endif		// GL_EXT_gpu_program_parameters

#ifdef GL_EXT_multi_draw_arrays
extern PFNGLMULTIDRAWARRAYSEXTPROC glMultiDrawArraysEXT;
extern PFNGLMULTIDRAWELEMENTSEXTPROC glMultiDrawElementsEXT;
#endif		// GL_EXT_multi_draw_arrays

#ifdef GL_NVX_conditional_render
extern PFNGLBEGINCONDITIONALRENDERNVXPROC glBeginConditionalRenderNVX;
extern PFNGLENDCONDITIONALRENDERNVXPROC glEndConditionalRenderNVX;
#endif		// GL_NVX_conditional_render

#ifdef GL_NV_bindless_multi_draw_indirect
extern PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC glMultiDrawArraysIndirectBindlessNV;
extern PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC glMultiDrawElementsIndirectBindlessNV;
#endif		// GL_NV_bindless_multi_draw_indirect

#ifdef GL_NV_bindless_multi_draw_indirect_count
extern PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC glMultiDrawArraysIndirectBindlessCountNV;
extern PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC glMultiDrawElementsIndirectBindlessCountNV;
#endif		// GL_NV_bindless_multi_draw_indirect_count

#ifdef GL_NV_bindless_texture
extern PFNGLGETTEXTUREHANDLENVPROC glGetTextureHandleNV;
extern PFNGLGETTEXTURESAMPLERHANDLENVPROC glGetTextureSamplerHandleNV;
extern PFNGLMAKETEXTUREHANDLERESIDENTNVPROC glMakeTextureHandleResidentNV;
extern PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC glMakeTextureHandleNonResidentNV;
extern PFNGLGETIMAGEHANDLENVPROC glGetImageHandleNV;
extern PFNGLMAKEIMAGEHANDLERESIDENTNVPROC glMakeImageHandleResidentNV;
extern PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC glMakeImageHandleNonResidentNV;
extern PFNGLUNIFORMHANDLEUI64NVPROC glUniformHandleui64NV;
extern PFNGLUNIFORMHANDLEUI64VNVPROC glUniformHandleui64vNV;
extern PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC glProgramUniformHandleui64NV;
extern PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC glProgramUniformHandleui64vNV;
extern PFNGLISTEXTUREHANDLERESIDENTNVPROC glIsTextureHandleResidentNV;
extern PFNGLISIMAGEHANDLERESIDENTNVPROC glIsImageHandleResidentNV;
#endif		// GL_NV_bindless_texture

#ifdef GL_NV_copy_image
extern PFNGLCOPYIMAGESUBDATANVPROC glCopyImageSubDataNV;
#endif		// GL_NV_copy_image

#ifdef GL_NV_draw_texture
extern PFNGLDRAWTEXTURENVPROC glDrawTextureNV;
#endif		// GL_NV_draw_texture

#ifdef GL_NV_texture_barrier
extern PFNGLTEXTUREBARRIERNVPROC glTextureBarrierNV;
#endif		// GL_NV_texture_barrier

#ifdef GL_NV_vertex_attrib_integer_64bit
extern PFNGLVERTEXATTRIBL1I64NVPROC glVertexAttribL1i64NV;
extern PFNGLVERTEXATTRIBL2I64NVPROC glVertexAttribL2i64NV;
extern PFNGLVERTEXATTRIBL3I64NVPROC glVertexAttribL3i64NV;
extern PFNGLVERTEXATTRIBL4I64NVPROC glVertexAttribL4i64NV;
extern PFNGLVERTEXATTRIBL1I64VNVPROC glVertexAttribL1i64vNV;
extern PFNGLVERTEXATTRIBL2I64VNVPROC glVertexAttribL2i64vNV;
extern PFNGLVERTEXATTRIBL3I64VNVPROC glVertexAttribL3i64vNV;
extern PFNGLVERTEXATTRIBL4I64VNVPROC glVertexAttribL4i64vNV;
extern PFNGLVERTEXATTRIBL1UI64NVPROC glVertexAttribL1ui64NV;
extern PFNGLVERTEXATTRIBL2UI64NVPROC glVertexAttribL2ui64NV;
extern PFNGLVERTEXATTRIBL3UI64NVPROC glVertexAttribL3ui64NV;
extern PFNGLVERTEXATTRIBL4UI64NVPROC glVertexAttribL4ui64NV;
extern PFNGLVERTEXATTRIBL1UI64VNVPROC glVertexAttribL1ui64vNV;
extern PFNGLVERTEXATTRIBL2UI64VNVPROC glVertexAttribL2ui64vNV;
extern PFNGLVERTEXATTRIBL3UI64VNVPROC glVertexAttribL3ui64vNV;
extern PFNGLVERTEXATTRIBL4UI64VNVPROC glVertexAttribL4ui64vNV;
extern PFNGLGETVERTEXATTRIBLI64VNVPROC glGetVertexAttribLi64vNV;
extern PFNGLGETVERTEXATTRIBLUI64VNVPROC glGetVertexAttribLui64vNV;
extern PFNGLVERTEXATTRIBLFORMATNVPROC glVertexAttribLFormatNV;
#endif		// GL_NV_vertex_attrib_integer_64bit

#endif
//
// ----- GLX extensions --------
//

#ifdef NONO
#ifdef GLX_NV_copy_buffer
extern PFNGLXCOPYBUFFERSUBDATANVPROC glXCopyBufferSubDataNV;
extern PFNGLXNAMEDCOPYBUFFERSUBDATANVPROC glXNamedCopyBufferSubDataNV;
#endif		// GLX_NV_copy_buffer

#ifdef GLX_NV_copy_image
extern PFNGLXCOPYIMAGESUBDATANVPROC glXCopyImageSubDataNV;
#endif		// GLX_NV_copy_image

#ifdef GLX_NV_delay_before_swap
extern PFNGLXDELAYBEFORESWAPNVPROC glXDelayBeforeSwapNV;
#endif		// GLX_NV_delay_before_swap

#ifdef GLX_NV_swap_group
extern PFNGLXJOINSWAPGROUPNVPROC glXJoinSwapGroupNV;
extern PFNGLXBINDSWAPBARRIERNVPROC glXBindSwapBarrierNV;
extern PFNGLXQUERYSWAPGROUPNVPROC glXQuerySwapGroupNV;
extern PFNGLXQUERYMAXSWAPGROUPSNVPROC glXQueryMaxSwapGroupsNV;
extern PFNGLXQUERYFRAMECOUNTNVPROC glXQueryFrameCountNV;
extern PFNGLXRESETFRAMECOUNTNVPROC glXResetFrameCountNV;
#endif		// GLX_NV_swap_group

#ifdef GLX_SGI_swap_control
extern PFNGLXSWAPINTERVALSGIPROC glXSwapIntervalSGI;
#endif		// GLX_SGI_swap_control

#ifdef GLX_SGI_video_sync
extern PFNGLXGETVIDEOSYNCSGIPROC glXGetVideoSyncSGI;
extern PFNGLXWAITVIDEOSYNCSGIPROC glXWaitVideoSyncSGI;
#endif		// GLX_SGI_video_sync

#endif

void *GetGLProcAddress( char *buf );
int  StringSearch( char *pext, char *pstring );
int  CheckGLExtension(  char *pchname );
void CheckOpenGLVersion( void );
void CheckOpenGLExtensions( void );
void CheckGLXExtensions( void );
int  CheckGLXExtension( char *pchname );
void ExtensionInit( void );

// ----- GL extensions -----------

void Init_GL_AMD_multi_draw_indirect( void );
void Init_GL_ARB_draw_buffers_blend( void );
void Init_GL_ARB_draw_instanced( void );
void Init_GL_ARB_window_pos( void );
void Init_GL_EXT_draw_buffers2( void );
void Init_GL_EXT_draw_instanced( void );
void Init_GL_EXT_gpu_program_parameters( void );
void Init_GL_EXT_multi_draw_arrays( void );
void Init_GL_NVX_conditional_render( void );
void Init_GL_NV_bindless_multi_draw_indirect( void );
void Init_GL_NV_bindless_multi_draw_indirect_count( void );
void Init_GL_NV_bindless_texture( void );
void Init_GL_NV_copy_image( void );
void Init_GL_NV_draw_texture( void );
void Init_GL_NV_texture_barrier( void );
void Init_GL_NV_vertex_attrib_integer_64bit( void );

// ----- GLX extensions ---------

#ifdef _GLX

void Init_GLX_NV_copy_buffer( void );
void Init_GLX_NV_copy_image( void );
void Init_GLX_NV_delay_before_swap( void );
void Init_GLX_NV_swap_group( void );
void Init_GLX_SGI_swap_control( void );
void Init_GLX_SGI_video_sync( void );

#endif		// _GLX

#endif		// __EXTMANAGER__
