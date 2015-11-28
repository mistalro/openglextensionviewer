// --------------------------------------------------------------------------
// Header file for the CExtensionManager class
//
// Stored in file extmanager.cpp
//
// File:   extmanager.h
// Author: Automatic code generator
// Date:   Wed Nov 25 04:52:14 2015
// System: galacticcore
// User:   msar
// Script: extcode.txt
// Config: config.txt
// Path:   /home/msar/Desktop/demos/openglextensionviewer-code/viewer
//
// From: extcode.h (Internal version)
// --------------------------------------------------------------------------
//
// This file is based on the following header files:
//
// Set   1
// registry/wglext.h - Version 20150623
// registry/glext.h  - Version 20151120
// registry/glxext.h - Version 20150623
//
// --------------------------------------------------------------------------
//
// The following extensions are currently supported by this class:
//
// ----- 557 GL extensions ---------
//
//   1 GL_3DFX_multisample
//   2 GL_3DFX_tbuffer
//   3 GL_3DFX_texture_compression_FXT1
//   4 GL_AMD_blend_minmax_factor
//   5 GL_AMD_conservative_depth
//   6 GL_AMD_debug_output
//   7 GL_AMD_depth_clamp_separate
//   8 GL_AMD_draw_buffers_blend
//   9 GL_AMD_gcn_shader
//  10 GL_AMD_gpu_shader_int64
//  11 GL_AMD_interleaved_elements
//  12 GL_AMD_multi_draw_indirect
//  13 GL_AMD_name_gen_delete
//  14 GL_AMD_occlusion_query_event
//  15 GL_AMD_performance_monitor
//  16 GL_AMD_pinned_memory
//  17 GL_AMD_query_buffer_object
//  18 GL_AMD_sample_positions
//  19 GL_AMD_seamless_cubemap_per_texture
//  20 GL_AMD_shader_atomic_counter_ops
//  21 GL_AMD_shader_stencil_export
//  22 GL_AMD_shader_trinary_minmax
//  23 GL_AMD_sparse_texture
//  24 GL_AMD_stencil_operation_extended
//  25 GL_AMD_texture_texture4
//  26 GL_AMD_transform_feedback3_lines_triangles
//  27 GL_AMD_transform_feedback4
//  28 GL_AMD_vertex_shader_layer
//  29 GL_AMD_vertex_shader_tessellator
//  30 GL_AMD_vertex_shader_viewport_index
//  31 GL_APPLE_aux_depth_stencil
//  32 GL_APPLE_client_storage
//  33 GL_APPLE_element_array
//  34 GL_APPLE_fence
//  35 GL_APPLE_float_pixels
//  36 GL_APPLE_flush_buffer_range
//  37 GL_APPLE_object_purgeable
//  38 GL_APPLE_rgb_422
//  39 GL_APPLE_row_bytes
//  40 GL_APPLE_specular_vector
//  41 GL_APPLE_texture_range
//  42 GL_APPLE_transform_hint
//  43 GL_APPLE_vertex_array_object
//  44 GL_APPLE_vertex_array_range
//  45 GL_APPLE_vertex_program_evaluators
//  46 GL_APPLE_ycbcr_422
//  47 GL_ARB_ES2_compatibility
//  48 GL_ARB_ES3_1_compatibility
//  49 GL_ARB_ES3_2_compatibility
//  50 GL_ARB_ES3_compatibility
//  51 GL_ARB_arrays_of_arrays
//  52 GL_ARB_base_instance
//  53 GL_ARB_bindless_texture
//  54 GL_ARB_blend_func_extended
//  55 GL_ARB_buffer_storage
//  56 GL_ARB_cl_event
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
//  89 GL_ARB_fragment_shader_interlock
//  90 GL_ARB_framebuffer_no_attachments
//  91 GL_ARB_framebuffer_object
//  92 GL_ARB_framebuffer_sRGB
//  93 GL_ARB_geometry_shader4
//  94 GL_ARB_get_program_binary
//  95 GL_ARB_get_texture_sub_image
//  96 GL_ARB_gpu_shader5
//  97 GL_ARB_gpu_shader_fp64
//  98 GL_ARB_gpu_shader_int64
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
// 109 GL_ARB_matrix_palette
// 110 GL_ARB_multi_bind
// 111 GL_ARB_multi_draw_indirect
// 112 GL_ARB_multisample
// 113 GL_ARB_multitexture
// 114 GL_ARB_occlusion_query
// 115 GL_ARB_occlusion_query2
// 116 GL_ARB_parallel_shader_compile
// 117 GL_ARB_pipeline_statistics_query
// 118 GL_ARB_pixel_buffer_object
// 119 GL_ARB_point_parameters
// 120 GL_ARB_point_sprite
// 121 GL_ARB_post_depth_coverage
// 122 GL_ARB_program_interface_query
// 123 GL_ARB_provoking_vertex
// 124 GL_ARB_query_buffer_object
// 125 GL_ARB_robust_buffer_access_behavior
// 126 GL_ARB_robustness
// 127 GL_ARB_robustness_isolation
// 128 GL_ARB_sample_locations
// 129 GL_ARB_sample_shading
// 130 GL_ARB_sampler_objects
// 131 GL_ARB_seamless_cube_map
// 132 GL_ARB_seamless_cubemap_per_texture
// 133 GL_ARB_separate_shader_objects
// 134 GL_ARB_shader_atomic_counter_ops
// 135 GL_ARB_shader_atomic_counters
// 136 GL_ARB_shader_ballot
// 137 GL_ARB_shader_bit_encoding
// 138 GL_ARB_shader_clock
// 139 GL_ARB_shader_draw_parameters
// 140 GL_ARB_shader_group_vote
// 141 GL_ARB_shader_image_load_store
// 142 GL_ARB_shader_image_size
// 143 GL_ARB_shader_objects
// 144 GL_ARB_shader_precision
// 145 GL_ARB_shader_stencil_export
// 146 GL_ARB_shader_storage_buffer_object
// 147 GL_ARB_shader_subroutine
// 148 GL_ARB_shader_texture_image_samples
// 149 GL_ARB_shader_texture_lod
// 150 GL_ARB_shader_viewport_layer_array
// 151 GL_ARB_shading_language_100
// 152 GL_ARB_shading_language_420pack
// 153 GL_ARB_shading_language_include
// 154 GL_ARB_shading_language_packing
// 155 GL_ARB_shadow
// 156 GL_ARB_shadow_ambient
// 157 GL_ARB_sparse_buffer
// 158 GL_ARB_sparse_texture
// 159 GL_ARB_sparse_texture2
// 160 GL_ARB_sparse_texture_clamp
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
// 178 GL_ARB_texture_filter_minmax
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
// 206 GL_ARB_vertex_blend
// 207 GL_ARB_vertex_buffer_object
// 208 GL_ARB_vertex_program
// 209 GL_ARB_vertex_shader
// 210 GL_ARB_vertex_type_10f_11f_11f_rev
// 211 GL_ARB_vertex_type_2_10_10_10_rev
// 212 GL_ARB_viewport_array
// 213 GL_ARB_window_pos
// 214 GL_ATI_draw_buffers
// 215 GL_ATI_element_array
// 216 GL_ATI_envmap_bumpmap
// 217 GL_ATI_fragment_shader
// 218 GL_ATI_map_object_buffer
// 219 GL_ATI_meminfo
// 220 GL_ATI_pixel_format_float
// 221 GL_ATI_pn_triangles
// 222 GL_ATI_separate_stencil
// 223 GL_ATI_text_fragment_shader
// 224 GL_ATI_texture_env_combine3
// 225 GL_ATI_texture_float
// 226 GL_ATI_texture_mirror_once
// 227 GL_ATI_vertex_array_object
// 228 GL_ATI_vertex_attrib_array_object
// 229 GL_ATI_vertex_streams
// 230 GL_EXT_422_pixels
// 231 GL_EXT_abgr
// 232 GL_EXT_bgra
// 233 GL_EXT_bindable_uniform
// 234 GL_EXT_blend_color
// 235 GL_EXT_blend_equation_separate
// 236 GL_EXT_blend_func_separate
// 237 GL_EXT_blend_logic_op
// 238 GL_EXT_blend_minmax
// 239 GL_EXT_blend_subtract
// 240 GL_EXT_clip_volume_hint
// 241 GL_EXT_cmyka
// 242 GL_EXT_color_subtable
// 243 GL_EXT_compiled_vertex_array
// 244 GL_EXT_convolution
// 245 GL_EXT_coordinate_frame
// 246 GL_EXT_copy_texture
// 247 GL_EXT_cull_vertex
// 248 GL_EXT_debug_label
// 249 GL_EXT_debug_marker
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
// 264 GL_EXT_histogram
// 265 GL_EXT_index_array_formats
// 266 GL_EXT_index_func
// 267 GL_EXT_index_material
// 268 GL_EXT_index_texture
// 269 GL_EXT_light_texture
// 270 GL_EXT_misc_attribute
// 271 GL_EXT_multi_draw_arrays
// 272 GL_EXT_multisample
// 273 GL_EXT_packed_depth_stencil
// 274 GL_EXT_packed_float
// 275 GL_EXT_packed_pixels
// 276 GL_EXT_paletted_texture
// 277 GL_EXT_pixel_buffer_object
// 278 GL_EXT_pixel_transform
// 279 GL_EXT_pixel_transform_color_table
// 280 GL_EXT_point_parameters
// 281 GL_EXT_polygon_offset
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
// 294 GL_EXT_shared_texture_palette
// 295 GL_EXT_sparse_texture2
// 296 GL_EXT_stencil_clear_tag
// 297 GL_EXT_stencil_two_side
// 298 GL_EXT_stencil_wrap
// 299 GL_EXT_subtexture
// 300 GL_EXT_texture
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
// 317 GL_EXT_texture_perturb_normal
// 318 GL_EXT_texture_sRGB
// 319 GL_EXT_texture_sRGB_decode
// 320 GL_EXT_texture_shared_exponent
// 321 GL_EXT_texture_snorm
// 322 GL_EXT_texture_swizzle
// 323 GL_EXT_timer_query
// 324 GL_EXT_transform_feedback
// 325 GL_EXT_vertex_array
// 326 GL_EXT_vertex_array_bgra
// 327 GL_EXT_vertex_attrib_64bit
// 328 GL_EXT_vertex_shader
// 329 GL_EXT_vertex_weighting
// 330 GL_EXT_x11_sync_object
// 331 GL_GREMEDY_frame_terminator
// 332 GL_GREMEDY_string_marker
// 333 GL_HP_convolution_border_modes
// 334 GL_HP_image_transform
// 335 GL_HP_occlusion_test
// 336 GL_HP_texture_lighting
// 337 GL_IBM_cull_vertex
// 338 GL_IBM_multimode_draw_arrays
// 339 GL_IBM_rasterpos_clip
// 340 GL_IBM_static_data
// 341 GL_IBM_texture_mirrored_repeat
// 342 GL_IBM_vertex_array_lists
// 343 GL_INGR_blend_func_separate
// 344 GL_INGR_color_clamp
// 345 GL_INGR_interlace_read
// 346 GL_INTEL_fragment_shader_ordering
// 347 GL_INTEL_framebuffer_CMAA
// 348 GL_INTEL_map_texture
// 349 GL_INTEL_parallel_arrays
// 350 GL_INTEL_performance_query
// 351 GL_KHR_blend_equation_advanced
// 352 GL_KHR_blend_equation_advanced_coherent
// 353 GL_KHR_context_flush_control
// 354 GL_KHR_debug
// 355 GL_KHR_no_error
// 356 GL_KHR_robust_buffer_access_behavior
// 357 GL_KHR_robustness
// 358 GL_KHR_texture_compression_astc_hdr
// 359 GL_KHR_texture_compression_astc_ldr
// 360 GL_KHR_texture_compression_astc_sliced_3d
// 361 GL_MESAX_texture_stack
// 362 GL_MESA_pack_invert
// 363 GL_MESA_resize_buffers
// 364 GL_MESA_window_pos
// 365 GL_MESA_ycbcr_texture
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
// 381 GL_NV_deep_texture3D
// 382 GL_NV_depth_buffer_float
// 383 GL_NV_depth_clamp
// 384 GL_NV_draw_texture
// 385 GL_NV_evaluators
// 386 GL_NV_explicit_multisample
// 387 GL_NV_fence
// 388 GL_NV_fill_rectangle
// 389 GL_NV_float_buffer
// 390 GL_NV_fog_distance
// 391 GL_NV_fragment_coverage_to_color
// 392 GL_NV_fragment_program
// 393 GL_NV_fragment_program2
// 394 GL_NV_fragment_program4
// 395 GL_NV_fragment_program_option
// 396 GL_NV_fragment_shader_interlock
// 397 GL_NV_framebuffer_mixed_samples
// 398 GL_NV_framebuffer_multisample_coverage
// 399 GL_NV_geometry_program4
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
// 419 GL_NV_present_video
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
// 430 GL_NV_shader_buffer_store
// 431 GL_NV_shader_storage_buffer_object
// 432 GL_NV_shader_thread_group
// 433 GL_NV_shader_thread_shuffle
// 434 GL_NV_tessellation_program5
// 435 GL_NV_texgen_emboss
// 436 GL_NV_texgen_reflection
// 437 GL_NV_texture_barrier
// 438 GL_NV_texture_compression_vtc
// 439 GL_NV_texture_env_combine4
// 440 GL_NV_texture_expand_normal
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
// 459 GL_NV_vertex_program4
// 460 GL_NV_video_capture
// 461 GL_NV_viewport_array2
// 462 GL_OES_byte_coordinates
// 463 GL_OES_compressed_paletted_texture
// 464 GL_OES_fixed_point
// 465 GL_OES_query_matrix
// 466 GL_OES_read_format
// 467 GL_OES_single_precision
// 468 GL_OML_interlace
// 469 GL_OML_resample
// 470 GL_OML_subsample
// 471 GL_OVR_multiview
// 472 GL_OVR_multiview2
// 473 GL_PGI_misc_hints
// 474 GL_PGI_vertex_hints
// 475 GL_REND_screen_coordinates
// 476 GL_S3_s3tc
// 477 GL_SGIS_detail_texture
// 478 GL_SGIS_fog_function
// 479 GL_SGIS_generate_mipmap
// 480 GL_SGIS_multisample
// 481 GL_SGIS_pixel_texture
// 482 GL_SGIS_point_line_texgen
// 483 GL_SGIS_point_parameters
// 484 GL_SGIS_sharpen_texture
// 485 GL_SGIS_texture4D
// 486 GL_SGIS_texture_border_clamp
// 487 GL_SGIS_texture_color_mask
// 488 GL_SGIS_texture_edge_clamp
// 489 GL_SGIS_texture_filter4
// 490 GL_SGIS_texture_lod
// 491 GL_SGIS_texture_select
// 492 GL_SGIX_async
// 493 GL_SGIX_async_histogram
// 494 GL_SGIX_async_pixel
// 495 GL_SGIX_blend_alpha_minmax
// 496 GL_SGIX_calligraphic_fragment
// 497 GL_SGIX_clipmap
// 498 GL_SGIX_convolution_accuracy
// 499 GL_SGIX_depth_pass_instrument
// 500 GL_SGIX_depth_texture
// 501 GL_SGIX_flush_raster
// 502 GL_SGIX_fog_offset
// 503 GL_SGIX_fragment_lighting
// 504 GL_SGIX_framezoom
// 505 GL_SGIX_igloo_interface
// 506 GL_SGIX_instruments
// 507 GL_SGIX_interlace
// 508 GL_SGIX_ir_instrument1
// 509 GL_SGIX_list_priority
// 510 GL_SGIX_pixel_texture
// 511 GL_SGIX_pixel_tiles
// 512 GL_SGIX_polynomial_ffd
// 513 GL_SGIX_reference_plane
// 514 GL_SGIX_resample
// 515 GL_SGIX_scalebias_hint
// 516 GL_SGIX_shadow
// 517 GL_SGIX_shadow_ambient
// 518 GL_SGIX_sprite
// 519 GL_SGIX_subsample
// 520 GL_SGIX_tag_sample_buffer
// 521 GL_SGIX_texture_add_env
// 522 GL_SGIX_texture_coordinate_clamp
// 523 GL_SGIX_texture_lod_bias
// 524 GL_SGIX_texture_multi_buffer
// 525 GL_SGIX_texture_scale_bias
// 526 GL_SGIX_vertex_preclip
// 527 GL_SGIX_ycrcb
// 528 GL_SGIX_ycrcb_subsample
// 529 GL_SGIX_ycrcba
// 530 GL_SGI_color_matrix
// 531 GL_SGI_color_table
// 532 GL_SGI_texture_color_table
// 533 GL_SUNX_constant_data
// 534 GL_SUN_convolution_border_modes
// 535 GL_SUN_global_alpha
// 536 GL_SUN_mesh_array
// 537 GL_SUN_slice_accum
// 538 GL_SUN_triangle_list
// 539 GL_SUN_vertex
// 540 GL_VERSION_1_2
// 541 GL_VERSION_1_3
// 542 GL_VERSION_1_4
// 543 GL_VERSION_1_5
// 544 GL_VERSION_2_0
// 545 GL_VERSION_2_1
// 546 GL_VERSION_3_0
// 547 GL_VERSION_3_1
// 548 GL_VERSION_3_2
// 549 GL_VERSION_3_3
// 550 GL_VERSION_4_0
// 551 GL_VERSION_4_1
// 552 GL_VERSION_4_2
// 553 GL_VERSION_4_3
// 554 GL_VERSION_4_4
// 555 GL_VERSION_4_5
// 556 GL_WIN_phong_shading
// 557 GL_WIN_specular_fog
// --------------------------------------------------------------------------

#define LOAD_LIBRARY

#ifndef __EXTMANAGER__
#define __EXTMANAGER__

class CExtensionManager
{
public:
// Extension presence flags


void *m_libhandler;
int m_OpenGL12;
int m_OpenGL13;
int m_OpenGL14;
int m_OpenGL15;
int m_OpenGL20;
int m_OpenGL21;
int m_OpenGL30;
int m_OpenGL31;
int m_OpenGL32;
int m_OpenGL33;
int m_OpenGL40;
int m_OpenGL41;
int m_OpenGL42;
int m_OpenGL43;
int m_OpenGL44;
int m_OpenGL45;

int m_GL_3DFX_multisample;
int m_GL_3DFX_tbuffer;
int m_GL_3DFX_texture_compression_FXT1;
int m_GL_AMD_blend_minmax_factor;
int m_GL_AMD_conservative_depth;
int m_GL_AMD_debug_output;
int m_GL_AMD_depth_clamp_separate;
int m_GL_AMD_draw_buffers_blend;
int m_GL_AMD_gcn_shader;
int m_GL_AMD_gpu_shader_int64;
int m_GL_AMD_interleaved_elements;
int m_GL_AMD_multi_draw_indirect;
int m_GL_AMD_name_gen_delete;
int m_GL_AMD_occlusion_query_event;
int m_GL_AMD_performance_monitor;
int m_GL_AMD_pinned_memory;
int m_GL_AMD_query_buffer_object;
int m_GL_AMD_sample_positions;
int m_GL_AMD_seamless_cubemap_per_texture;
int m_GL_AMD_shader_atomic_counter_ops;
int m_GL_AMD_shader_stencil_export;
int m_GL_AMD_shader_trinary_minmax;
int m_GL_AMD_sparse_texture;
int m_GL_AMD_stencil_operation_extended;
int m_GL_AMD_texture_texture4;
int m_GL_AMD_transform_feedback3_lines_triangles;
int m_GL_AMD_transform_feedback4;
int m_GL_AMD_vertex_shader_layer;
int m_GL_AMD_vertex_shader_tessellator;
int m_GL_AMD_vertex_shader_viewport_index;
int m_GL_APPLE_aux_depth_stencil;
int m_GL_APPLE_client_storage;
int m_GL_APPLE_element_array;
int m_GL_APPLE_fence;
int m_GL_APPLE_float_pixels;
int m_GL_APPLE_flush_buffer_range;
int m_GL_APPLE_object_purgeable;
int m_GL_APPLE_rgb_422;
int m_GL_APPLE_row_bytes;
int m_GL_APPLE_specular_vector;
int m_GL_APPLE_texture_range;
int m_GL_APPLE_transform_hint;
int m_GL_APPLE_vertex_array_object;
int m_GL_APPLE_vertex_array_range;
int m_GL_APPLE_vertex_program_evaluators;
int m_GL_APPLE_ycbcr_422;
int m_GL_ARB_ES2_compatibility;
int m_GL_ARB_ES3_1_compatibility;
int m_GL_ARB_ES3_2_compatibility;
int m_GL_ARB_ES3_compatibility;
int m_GL_ARB_arrays_of_arrays;
int m_GL_ARB_base_instance;
int m_GL_ARB_bindless_texture;
int m_GL_ARB_blend_func_extended;
int m_GL_ARB_buffer_storage;
int m_GL_ARB_cl_event;
int m_GL_ARB_clear_buffer_object;
int m_GL_ARB_clear_texture;
int m_GL_ARB_clip_control;
int m_GL_ARB_color_buffer_float;
int m_GL_ARB_compatibility;
int m_GL_ARB_compressed_texture_pixel_storage;
int m_GL_ARB_compute_shader;
int m_GL_ARB_compute_variable_group_size;
int m_GL_ARB_conditional_render_inverted;
int m_GL_ARB_conservative_depth;
int m_GL_ARB_copy_buffer;
int m_GL_ARB_copy_image;
int m_GL_ARB_cull_distance;
int m_GL_ARB_debug_output;
int m_GL_ARB_depth_buffer_float;
int m_GL_ARB_depth_clamp;
int m_GL_ARB_depth_texture;
int m_GL_ARB_derivative_control;
int m_GL_ARB_direct_state_access;
int m_GL_ARB_draw_buffers;
int m_GL_ARB_draw_buffers_blend;
int m_GL_ARB_draw_elements_base_vertex;
int m_GL_ARB_draw_indirect;
int m_GL_ARB_draw_instanced;
int m_GL_ARB_enhanced_layouts;
int m_GL_ARB_explicit_attrib_location;
int m_GL_ARB_explicit_uniform_location;
int m_GL_ARB_fragment_coord_conventions;
int m_GL_ARB_fragment_layer_viewport;
int m_GL_ARB_fragment_program;
int m_GL_ARB_fragment_program_shadow;
int m_GL_ARB_fragment_shader;
int m_GL_ARB_fragment_shader_interlock;
int m_GL_ARB_framebuffer_no_attachments;
int m_GL_ARB_framebuffer_object;
int m_GL_ARB_framebuffer_sRGB;
int m_GL_ARB_geometry_shader4;
int m_GL_ARB_get_program_binary;
int m_GL_ARB_get_texture_sub_image;
int m_GL_ARB_gpu_shader5;
int m_GL_ARB_gpu_shader_fp64;
int m_GL_ARB_gpu_shader_int64;
int m_GL_ARB_half_float_pixel;
int m_GL_ARB_half_float_vertex;
int m_GL_ARB_imaging;
int m_GL_ARB_indirect_parameters;
int m_GL_ARB_instanced_arrays;
int m_GL_ARB_internalformat_query;
int m_GL_ARB_internalformat_query2;
int m_GL_ARB_invalidate_subdata;
int m_GL_ARB_map_buffer_alignment;
int m_GL_ARB_map_buffer_range;
int m_GL_ARB_matrix_palette;
int m_GL_ARB_multi_bind;
int m_GL_ARB_multi_draw_indirect;
int m_GL_ARB_multisample;
int m_GL_ARB_multitexture;
int m_GL_ARB_occlusion_query;
int m_GL_ARB_occlusion_query2;
int m_GL_ARB_parallel_shader_compile;
int m_GL_ARB_pipeline_statistics_query;
int m_GL_ARB_pixel_buffer_object;
int m_GL_ARB_point_parameters;
int m_GL_ARB_point_sprite;
int m_GL_ARB_post_depth_coverage;
int m_GL_ARB_program_interface_query;
int m_GL_ARB_provoking_vertex;
int m_GL_ARB_query_buffer_object;
int m_GL_ARB_robust_buffer_access_behavior;
int m_GL_ARB_robustness;
int m_GL_ARB_robustness_isolation;
int m_GL_ARB_sample_locations;
int m_GL_ARB_sample_shading;
int m_GL_ARB_sampler_objects;
int m_GL_ARB_seamless_cube_map;
int m_GL_ARB_seamless_cubemap_per_texture;
int m_GL_ARB_separate_shader_objects;
int m_GL_ARB_shader_atomic_counter_ops;
int m_GL_ARB_shader_atomic_counters;
int m_GL_ARB_shader_ballot;
int m_GL_ARB_shader_bit_encoding;
int m_GL_ARB_shader_clock;
int m_GL_ARB_shader_draw_parameters;
int m_GL_ARB_shader_group_vote;
int m_GL_ARB_shader_image_load_store;
int m_GL_ARB_shader_image_size;
int m_GL_ARB_shader_objects;
int m_GL_ARB_shader_precision;
int m_GL_ARB_shader_stencil_export;
int m_GL_ARB_shader_storage_buffer_object;
int m_GL_ARB_shader_subroutine;
int m_GL_ARB_shader_texture_image_samples;
int m_GL_ARB_shader_texture_lod;
int m_GL_ARB_shader_viewport_layer_array;
int m_GL_ARB_shading_language_100;
int m_GL_ARB_shading_language_420pack;
int m_GL_ARB_shading_language_include;
int m_GL_ARB_shading_language_packing;
int m_GL_ARB_shadow;
int m_GL_ARB_shadow_ambient;
int m_GL_ARB_sparse_buffer;
int m_GL_ARB_sparse_texture;
int m_GL_ARB_sparse_texture2;
int m_GL_ARB_sparse_texture_clamp;
int m_GL_ARB_stencil_texturing;
int m_GL_ARB_sync;
int m_GL_ARB_tessellation_shader;
int m_GL_ARB_texture_barrier;
int m_GL_ARB_texture_border_clamp;
int m_GL_ARB_texture_buffer_object;
int m_GL_ARB_texture_buffer_object_rgb32;
int m_GL_ARB_texture_buffer_range;
int m_GL_ARB_texture_compression;
int m_GL_ARB_texture_compression_bptc;
int m_GL_ARB_texture_compression_rgtc;
int m_GL_ARB_texture_cube_map;
int m_GL_ARB_texture_cube_map_array;
int m_GL_ARB_texture_env_add;
int m_GL_ARB_texture_env_combine;
int m_GL_ARB_texture_env_crossbar;
int m_GL_ARB_texture_env_dot3;
int m_GL_ARB_texture_filter_minmax;
int m_GL_ARB_texture_float;
int m_GL_ARB_texture_gather;
int m_GL_ARB_texture_mirror_clamp_to_edge;
int m_GL_ARB_texture_mirrored_repeat;
int m_GL_ARB_texture_multisample;
int m_GL_ARB_texture_non_power_of_two;
int m_GL_ARB_texture_query_levels;
int m_GL_ARB_texture_query_lod;
int m_GL_ARB_texture_rectangle;
int m_GL_ARB_texture_rg;
int m_GL_ARB_texture_rgb10_a2ui;
int m_GL_ARB_texture_stencil8;
int m_GL_ARB_texture_storage;
int m_GL_ARB_texture_storage_multisample;
int m_GL_ARB_texture_swizzle;
int m_GL_ARB_texture_view;
int m_GL_ARB_timer_query;
int m_GL_ARB_transform_feedback2;
int m_GL_ARB_transform_feedback3;
int m_GL_ARB_transform_feedback_instanced;
int m_GL_ARB_transform_feedback_overflow_query;
int m_GL_ARB_transpose_matrix;
int m_GL_ARB_uniform_buffer_object;
int m_GL_ARB_vertex_array_bgra;
int m_GL_ARB_vertex_array_object;
int m_GL_ARB_vertex_attrib_64bit;
int m_GL_ARB_vertex_attrib_binding;
int m_GL_ARB_vertex_blend;
int m_GL_ARB_vertex_buffer_object;
int m_GL_ARB_vertex_program;
int m_GL_ARB_vertex_shader;
int m_GL_ARB_vertex_type_10f_11f_11f_rev;
int m_GL_ARB_vertex_type_2_10_10_10_rev;
int m_GL_ARB_viewport_array;
int m_GL_ARB_window_pos;
int m_GL_ATI_draw_buffers;
int m_GL_ATI_element_array;
int m_GL_ATI_envmap_bumpmap;
int m_GL_ATI_fragment_shader;
int m_GL_ATI_map_object_buffer;
int m_GL_ATI_meminfo;
int m_GL_ATI_pixel_format_float;
int m_GL_ATI_pn_triangles;
int m_GL_ATI_separate_stencil;
int m_GL_ATI_text_fragment_shader;
int m_GL_ATI_texture_env_combine3;
int m_GL_ATI_texture_float;
int m_GL_ATI_texture_mirror_once;
int m_GL_ATI_vertex_array_object;
int m_GL_ATI_vertex_attrib_array_object;
int m_GL_ATI_vertex_streams;
int m_GL_EXT_422_pixels;
int m_GL_EXT_abgr;
int m_GL_EXT_bgra;
int m_GL_EXT_bindable_uniform;
int m_GL_EXT_blend_color;
int m_GL_EXT_blend_equation_separate;
int m_GL_EXT_blend_func_separate;
int m_GL_EXT_blend_logic_op;
int m_GL_EXT_blend_minmax;
int m_GL_EXT_blend_subtract;
int m_GL_EXT_clip_volume_hint;
int m_GL_EXT_cmyka;
int m_GL_EXT_color_subtable;
int m_GL_EXT_compiled_vertex_array;
int m_GL_EXT_convolution;
int m_GL_EXT_coordinate_frame;
int m_GL_EXT_copy_texture;
int m_GL_EXT_cull_vertex;
int m_GL_EXT_debug_label;
int m_GL_EXT_debug_marker;
int m_GL_EXT_depth_bounds_test;
int m_GL_EXT_direct_state_access;
int m_GL_EXT_draw_buffers2;
int m_GL_EXT_draw_instanced;
int m_GL_EXT_draw_range_elements;
int m_GL_EXT_fog_coord;
int m_GL_EXT_framebuffer_blit;
int m_GL_EXT_framebuffer_multisample;
int m_GL_EXT_framebuffer_multisample_blit_scaled;
int m_GL_EXT_framebuffer_object;
int m_GL_EXT_framebuffer_sRGB;
int m_GL_EXT_geometry_shader4;
int m_GL_EXT_gpu_program_parameters;
int m_GL_EXT_gpu_shader4;
int m_GL_EXT_histogram;
int m_GL_EXT_index_array_formats;
int m_GL_EXT_index_func;
int m_GL_EXT_index_material;
int m_GL_EXT_index_texture;
int m_GL_EXT_light_texture;
int m_GL_EXT_misc_attribute;
int m_GL_EXT_multi_draw_arrays;
int m_GL_EXT_multisample;
int m_GL_EXT_packed_depth_stencil;
int m_GL_EXT_packed_float;
int m_GL_EXT_packed_pixels;
int m_GL_EXT_paletted_texture;
int m_GL_EXT_pixel_buffer_object;
int m_GL_EXT_pixel_transform;
int m_GL_EXT_pixel_transform_color_table;
int m_GL_EXT_point_parameters;
int m_GL_EXT_polygon_offset;
int m_GL_EXT_polygon_offset_clamp;
int m_GL_EXT_post_depth_coverage;
int m_GL_EXT_provoking_vertex;
int m_GL_EXT_raster_multisample;
int m_GL_EXT_rescale_normal;
int m_GL_EXT_secondary_color;
int m_GL_EXT_separate_shader_objects;
int m_GL_EXT_separate_specular_color;
int m_GL_EXT_shader_image_load_formatted;
int m_GL_EXT_shader_image_load_store;
int m_GL_EXT_shader_integer_mix;
int m_GL_EXT_shadow_funcs;
int m_GL_EXT_shared_texture_palette;
int m_GL_EXT_sparse_texture2;
int m_GL_EXT_stencil_clear_tag;
int m_GL_EXT_stencil_two_side;
int m_GL_EXT_stencil_wrap;
int m_GL_EXT_subtexture;
int m_GL_EXT_texture;
int m_GL_EXT_texture3D;
int m_GL_EXT_texture_array;
int m_GL_EXT_texture_buffer_object;
int m_GL_EXT_texture_compression_latc;
int m_GL_EXT_texture_compression_rgtc;
int m_GL_EXT_texture_compression_s3tc;
int m_GL_EXT_texture_cube_map;
int m_GL_EXT_texture_env_add;
int m_GL_EXT_texture_env_combine;
int m_GL_EXT_texture_env_dot3;
int m_GL_EXT_texture_filter_anisotropic;
int m_GL_EXT_texture_filter_minmax;
int m_GL_EXT_texture_integer;
int m_GL_EXT_texture_lod_bias;
int m_GL_EXT_texture_mirror_clamp;
int m_GL_EXT_texture_object;
int m_GL_EXT_texture_perturb_normal;
int m_GL_EXT_texture_sRGB;
int m_GL_EXT_texture_sRGB_decode;
int m_GL_EXT_texture_shared_exponent;
int m_GL_EXT_texture_snorm;
int m_GL_EXT_texture_swizzle;
int m_GL_EXT_timer_query;
int m_GL_EXT_transform_feedback;
int m_GL_EXT_vertex_array;
int m_GL_EXT_vertex_array_bgra;
int m_GL_EXT_vertex_attrib_64bit;
int m_GL_EXT_vertex_shader;
int m_GL_EXT_vertex_weighting;
int m_GL_EXT_x11_sync_object;
int m_GL_GREMEDY_frame_terminator;
int m_GL_GREMEDY_string_marker;
int m_GL_HP_convolution_border_modes;
int m_GL_HP_image_transform;
int m_GL_HP_occlusion_test;
int m_GL_HP_texture_lighting;
int m_GL_IBM_cull_vertex;
int m_GL_IBM_multimode_draw_arrays;
int m_GL_IBM_rasterpos_clip;
int m_GL_IBM_static_data;
int m_GL_IBM_texture_mirrored_repeat;
int m_GL_IBM_vertex_array_lists;
int m_GL_INGR_blend_func_separate;
int m_GL_INGR_color_clamp;
int m_GL_INGR_interlace_read;
int m_GL_INTEL_fragment_shader_ordering;
int m_GL_INTEL_framebuffer_CMAA;
int m_GL_INTEL_map_texture;
int m_GL_INTEL_parallel_arrays;
int m_GL_INTEL_performance_query;
int m_GL_KHR_blend_equation_advanced;
int m_GL_KHR_blend_equation_advanced_coherent;
int m_GL_KHR_context_flush_control;
int m_GL_KHR_debug;
int m_GL_KHR_no_error;
int m_GL_KHR_robust_buffer_access_behavior;
int m_GL_KHR_robustness;
int m_GL_KHR_texture_compression_astc_hdr;
int m_GL_KHR_texture_compression_astc_ldr;
int m_GL_KHR_texture_compression_astc_sliced_3d;
int m_GL_MESAX_texture_stack;
int m_GL_MESA_pack_invert;
int m_GL_MESA_resize_buffers;
int m_GL_MESA_window_pos;
int m_GL_MESA_ycbcr_texture;
int m_GL_NVX_conditional_render;
int m_GL_NVX_gpu_memory_info;
int m_GL_NV_bindless_multi_draw_indirect;
int m_GL_NV_bindless_multi_draw_indirect_count;
int m_GL_NV_bindless_texture;
int m_GL_NV_blend_equation_advanced;
int m_GL_NV_blend_equation_advanced_coherent;
int m_GL_NV_blend_square;
int m_GL_NV_command_list;
int m_GL_NV_compute_program5;
int m_GL_NV_conditional_render;
int m_GL_NV_conservative_raster;
int m_GL_NV_conservative_raster_dilate;
int m_GL_NV_copy_depth_to_color;
int m_GL_NV_copy_image;
int m_GL_NV_deep_texture3D;
int m_GL_NV_depth_buffer_float;
int m_GL_NV_depth_clamp;
int m_GL_NV_draw_texture;
int m_GL_NV_evaluators;
int m_GL_NV_explicit_multisample;
int m_GL_NV_fence;
int m_GL_NV_fill_rectangle;
int m_GL_NV_float_buffer;
int m_GL_NV_fog_distance;
int m_GL_NV_fragment_coverage_to_color;
int m_GL_NV_fragment_program;
int m_GL_NV_fragment_program2;
int m_GL_NV_fragment_program4;
int m_GL_NV_fragment_program_option;
int m_GL_NV_fragment_shader_interlock;
int m_GL_NV_framebuffer_mixed_samples;
int m_GL_NV_framebuffer_multisample_coverage;
int m_GL_NV_geometry_program4;
int m_GL_NV_geometry_shader4;
int m_GL_NV_geometry_shader_passthrough;
int m_GL_NV_gpu_program4;
int m_GL_NV_gpu_program5;
int m_GL_NV_gpu_program5_mem_extended;
int m_GL_NV_gpu_shader5;
int m_GL_NV_half_float;
int m_GL_NV_internalformat_sample_query;
int m_GL_NV_light_max_exponent;
int m_GL_NV_multisample_coverage;
int m_GL_NV_multisample_filter_hint;
int m_GL_NV_occlusion_query;
int m_GL_NV_packed_depth_stencil;
int m_GL_NV_parameter_buffer_object;
int m_GL_NV_parameter_buffer_object2;
int m_GL_NV_path_rendering;
int m_GL_NV_path_rendering_shared_edge;
int m_GL_NV_pixel_data_range;
int m_GL_NV_point_sprite;
int m_GL_NV_present_video;
int m_GL_NV_primitive_restart;
int m_GL_NV_register_combiners;
int m_GL_NV_register_combiners2;
int m_GL_NV_sample_locations;
int m_GL_NV_sample_mask_override_coverage;
int m_GL_NV_shader_atomic_counters;
int m_GL_NV_shader_atomic_float;
int m_GL_NV_shader_atomic_fp16_vector;
int m_GL_NV_shader_atomic_int64;
int m_GL_NV_shader_buffer_load;
int m_GL_NV_shader_buffer_store;
int m_GL_NV_shader_storage_buffer_object;
int m_GL_NV_shader_thread_group;
int m_GL_NV_shader_thread_shuffle;
int m_GL_NV_tessellation_program5;
int m_GL_NV_texgen_emboss;
int m_GL_NV_texgen_reflection;
int m_GL_NV_texture_barrier;
int m_GL_NV_texture_compression_vtc;
int m_GL_NV_texture_env_combine4;
int m_GL_NV_texture_expand_normal;
int m_GL_NV_texture_multisample;
int m_GL_NV_texture_rectangle;
int m_GL_NV_texture_shader;
int m_GL_NV_texture_shader2;
int m_GL_NV_texture_shader3;
int m_GL_NV_transform_feedback;
int m_GL_NV_transform_feedback2;
int m_GL_NV_uniform_buffer_unified_memory;
int m_GL_NV_vdpau_interop;
int m_GL_NV_vertex_array_range;
int m_GL_NV_vertex_array_range2;
int m_GL_NV_vertex_attrib_integer_64bit;
int m_GL_NV_vertex_buffer_unified_memory;
int m_GL_NV_vertex_program;
int m_GL_NV_vertex_program1_1;
int m_GL_NV_vertex_program2;
int m_GL_NV_vertex_program2_option;
int m_GL_NV_vertex_program3;
int m_GL_NV_vertex_program4;
int m_GL_NV_video_capture;
int m_GL_NV_viewport_array2;
int m_GL_OES_byte_coordinates;
int m_GL_OES_compressed_paletted_texture;
int m_GL_OES_fixed_point;
int m_GL_OES_query_matrix;
int m_GL_OES_read_format;
int m_GL_OES_single_precision;
int m_GL_OML_interlace;
int m_GL_OML_resample;
int m_GL_OML_subsample;
int m_GL_OVR_multiview;
int m_GL_OVR_multiview2;
int m_GL_PGI_misc_hints;
int m_GL_PGI_vertex_hints;
int m_GL_REND_screen_coordinates;
int m_GL_S3_s3tc;
int m_GL_SGIS_detail_texture;
int m_GL_SGIS_fog_function;
int m_GL_SGIS_generate_mipmap;
int m_GL_SGIS_multisample;
int m_GL_SGIS_pixel_texture;
int m_GL_SGIS_point_line_texgen;
int m_GL_SGIS_point_parameters;
int m_GL_SGIS_sharpen_texture;
int m_GL_SGIS_texture4D;
int m_GL_SGIS_texture_border_clamp;
int m_GL_SGIS_texture_color_mask;
int m_GL_SGIS_texture_edge_clamp;
int m_GL_SGIS_texture_filter4;
int m_GL_SGIS_texture_lod;
int m_GL_SGIS_texture_select;
int m_GL_SGIX_async;
int m_GL_SGIX_async_histogram;
int m_GL_SGIX_async_pixel;
int m_GL_SGIX_blend_alpha_minmax;
int m_GL_SGIX_calligraphic_fragment;
int m_GL_SGIX_clipmap;
int m_GL_SGIX_convolution_accuracy;
int m_GL_SGIX_depth_pass_instrument;
int m_GL_SGIX_depth_texture;
int m_GL_SGIX_flush_raster;
int m_GL_SGIX_fog_offset;
int m_GL_SGIX_fragment_lighting;
int m_GL_SGIX_framezoom;
int m_GL_SGIX_igloo_interface;
int m_GL_SGIX_instruments;
int m_GL_SGIX_interlace;
int m_GL_SGIX_ir_instrument1;
int m_GL_SGIX_list_priority;
int m_GL_SGIX_pixel_texture;
int m_GL_SGIX_pixel_tiles;
int m_GL_SGIX_polynomial_ffd;
int m_GL_SGIX_reference_plane;
int m_GL_SGIX_resample;
int m_GL_SGIX_scalebias_hint;
int m_GL_SGIX_shadow;
int m_GL_SGIX_shadow_ambient;
int m_GL_SGIX_sprite;
int m_GL_SGIX_subsample;
int m_GL_SGIX_tag_sample_buffer;
int m_GL_SGIX_texture_add_env;
int m_GL_SGIX_texture_coordinate_clamp;
int m_GL_SGIX_texture_lod_bias;
int m_GL_SGIX_texture_multi_buffer;
int m_GL_SGIX_texture_scale_bias;
int m_GL_SGIX_vertex_preclip;
int m_GL_SGIX_ycrcb;
int m_GL_SGIX_ycrcb_subsample;
int m_GL_SGIX_ycrcba;
int m_GL_SGI_color_matrix;
int m_GL_SGI_color_table;
int m_GL_SGI_texture_color_table;
int m_GL_SUNX_constant_data;
int m_GL_SUN_convolution_border_modes;
int m_GL_SUN_global_alpha;
int m_GL_SUN_mesh_array;
int m_GL_SUN_slice_accum;
int m_GL_SUN_triangle_list;
int m_GL_SUN_vertex;
int m_GL_VERSION_1_2;
int m_GL_VERSION_1_3;
int m_GL_VERSION_1_4;
int m_GL_VERSION_1_5;
int m_GL_VERSION_2_0;
int m_GL_VERSION_2_1;
int m_GL_VERSION_3_0;
int m_GL_VERSION_3_1;
int m_GL_VERSION_3_2;
int m_GL_VERSION_3_3;
int m_GL_VERSION_4_0;
int m_GL_VERSION_4_1;
int m_GL_VERSION_4_2;
int m_GL_VERSION_4_3;
int m_GL_VERSION_4_4;
int m_GL_VERSION_4_5;
int m_GL_WIN_phong_shading;
int m_GL_WIN_specular_fog;

//
// ----- GL extensions --------
//

#ifdef GL_3DFX_tbuffer
PFNGLTBUFFERMASK3DFXPROC glTbufferMask3DFX;
#endif		// GL_3DFX_tbuffer

#ifdef GL_AMD_draw_buffers_blend
PFNGLBLENDFUNCINDEXEDAMDPROC glBlendFuncIndexedAMD;
PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC glBlendFuncSeparateIndexedAMD;
PFNGLBLENDEQUATIONINDEXEDAMDPROC glBlendEquationIndexedAMD;
PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC glBlendEquationSeparateIndexedAMD;
#endif		// GL_AMD_draw_buffers_blend

#ifdef GL_AMD_multi_draw_indirect
PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC glMultiDrawArraysIndirectAMD;
PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC glMultiDrawElementsIndirectAMD;
#endif		// GL_AMD_multi_draw_indirect

#ifdef GL_ARB_draw_buffers_blend
PFNGLBLENDEQUATIONIARBPROC glBlendEquationiARB;
PFNGLBLENDEQUATIONSEPARATEIARBPROC glBlendEquationSeparateiARB;
PFNGLBLENDFUNCIARBPROC glBlendFunciARB;
PFNGLBLENDFUNCSEPARATEIARBPROC glBlendFuncSeparateiARB;
#endif		// GL_ARB_draw_buffers_blend

#ifdef GL_ARB_draw_instanced
PFNGLDRAWARRAYSINSTANCEDARBPROC glDrawArraysInstancedARB;
PFNGLDRAWELEMENTSINSTANCEDARBPROC glDrawElementsInstancedARB;
#endif		// GL_ARB_draw_instanced

#ifdef GL_ARB_window_pos
PFNGLWINDOWPOS2DARBPROC glWindowPos2dARB;
PFNGLWINDOWPOS2DVARBPROC glWindowPos2dvARB;
PFNGLWINDOWPOS2FARBPROC glWindowPos2fARB;
PFNGLWINDOWPOS2FVARBPROC glWindowPos2fvARB;
PFNGLWINDOWPOS2IARBPROC glWindowPos2iARB;
PFNGLWINDOWPOS2IVARBPROC glWindowPos2ivARB;
PFNGLWINDOWPOS2SARBPROC glWindowPos2sARB;
PFNGLWINDOWPOS2SVARBPROC glWindowPos2svARB;
PFNGLWINDOWPOS3DARBPROC glWindowPos3dARB;
PFNGLWINDOWPOS3DVARBPROC glWindowPos3dvARB;
PFNGLWINDOWPOS3FARBPROC glWindowPos3fARB;
PFNGLWINDOWPOS3FVARBPROC glWindowPos3fvARB;
PFNGLWINDOWPOS3IARBPROC glWindowPos3iARB;
PFNGLWINDOWPOS3IVARBPROC glWindowPos3ivARB;
PFNGLWINDOWPOS3SARBPROC glWindowPos3sARB;
PFNGLWINDOWPOS3SVARBPROC glWindowPos3svARB;
#endif		// GL_ARB_window_pos

#ifdef GL_ATI_map_object_buffer
PFNGLMAPOBJECTBUFFERATIPROC glMapObjectBufferATI;
PFNGLUNMAPOBJECTBUFFERATIPROC glUnmapObjectBufferATI;
#endif		// GL_ATI_map_object_buffer

#ifdef GL_ATI_vertex_attrib_array_object
PFNGLVERTEXATTRIBARRAYOBJECTATIPROC glVertexAttribArrayObjectATI;
PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC glGetVertexAttribArrayObjectfvATI;
PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC glGetVertexAttribArrayObjectivATI;
#endif		// GL_ATI_vertex_attrib_array_object

#ifdef GL_EXT_color_subtable
PFNGLCOLORSUBTABLEEXTPROC glColorSubTableEXT;
PFNGLCOPYCOLORSUBTABLEEXTPROC glCopyColorSubTableEXT;
#endif		// GL_EXT_color_subtable

#ifdef GL_EXT_copy_texture
PFNGLCOPYTEXIMAGE1DEXTPROC glCopyTexImage1DEXT;
PFNGLCOPYTEXIMAGE2DEXTPROC glCopyTexImage2DEXT;
PFNGLCOPYTEXSUBIMAGE1DEXTPROC glCopyTexSubImage1DEXT;
PFNGLCOPYTEXSUBIMAGE2DEXTPROC glCopyTexSubImage2DEXT;
PFNGLCOPYTEXSUBIMAGE3DEXTPROC glCopyTexSubImage3DEXT;
#endif		// GL_EXT_copy_texture

#ifdef GL_EXT_debug_marker
PFNGLINSERTEVENTMARKEREXTPROC glInsertEventMarkerEXT;
PFNGLPUSHGROUPMARKEREXTPROC glPushGroupMarkerEXT;
PFNGLPOPGROUPMARKEREXTPROC glPopGroupMarkerEXT;
#endif		// GL_EXT_debug_marker

#ifdef GL_EXT_draw_buffers2
PFNGLCOLORMASKINDEXEDEXTPROC glColorMaskIndexedEXT;
#endif		// GL_EXT_draw_buffers2

#ifdef GL_EXT_draw_instanced
PFNGLDRAWARRAYSINSTANCEDEXTPROC glDrawArraysInstancedEXT;
PFNGLDRAWELEMENTSINSTANCEDEXTPROC glDrawElementsInstancedEXT;
#endif		// GL_EXT_draw_instanced

#ifdef GL_EXT_gpu_program_parameters
PFNGLPROGRAMENVPARAMETERS4FVEXTPROC glProgramEnvParameters4fvEXT;
PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC glProgramLocalParameters4fvEXT;
#endif		// GL_EXT_gpu_program_parameters

#ifdef GL_EXT_multi_draw_arrays
PFNGLMULTIDRAWARRAYSEXTPROC glMultiDrawArraysEXT;
PFNGLMULTIDRAWELEMENTSEXTPROC glMultiDrawElementsEXT;
#endif		// GL_EXT_multi_draw_arrays

#ifdef GL_EXT_subtexture
PFNGLTEXSUBIMAGE1DEXTPROC glTexSubImage1DEXT;
PFNGLTEXSUBIMAGE2DEXTPROC glTexSubImage2DEXT;
#endif		// GL_EXT_subtexture

#ifdef GL_GREMEDY_frame_terminator
PFNGLFRAMETERMINATORGREMEDYPROC glFrameTerminatorGREMEDY;
#endif		// GL_GREMEDY_frame_terminator

#ifdef GL_GREMEDY_string_marker
PFNGLSTRINGMARKERGREMEDYPROC glStringMarkerGREMEDY;
#endif		// GL_GREMEDY_string_marker

#ifdef GL_IBM_multimode_draw_arrays
PFNGLMULTIMODEDRAWARRAYSIBMPROC glMultiModeDrawArraysIBM;
PFNGLMULTIMODEDRAWELEMENTSIBMPROC glMultiModeDrawElementsIBM;
#endif		// GL_IBM_multimode_draw_arrays

#ifdef GL_INGR_blend_func_separate
PFNGLBLENDFUNCSEPARATEINGRPROC glBlendFuncSeparateINGR;
#endif		// GL_INGR_blend_func_separate

#ifdef GL_INTEL_framebuffer_CMAA
PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC glApplyFramebufferAttachmentCMAAINTEL;
#endif		// GL_INTEL_framebuffer_CMAA

#ifdef GL_MESA_resize_buffers
PFNGLRESIZEBUFFERSMESAPROC glResizeBuffersMESA;
#endif		// GL_MESA_resize_buffers

#ifdef GL_MESA_window_pos
PFNGLWINDOWPOS2DMESAPROC glWindowPos2dMESA;
PFNGLWINDOWPOS2DVMESAPROC glWindowPos2dvMESA;
PFNGLWINDOWPOS2FMESAPROC glWindowPos2fMESA;
PFNGLWINDOWPOS2FVMESAPROC glWindowPos2fvMESA;
PFNGLWINDOWPOS2IMESAPROC glWindowPos2iMESA;
PFNGLWINDOWPOS2IVMESAPROC glWindowPos2ivMESA;
PFNGLWINDOWPOS2SMESAPROC glWindowPos2sMESA;
PFNGLWINDOWPOS2SVMESAPROC glWindowPos2svMESA;
PFNGLWINDOWPOS3DMESAPROC glWindowPos3dMESA;
PFNGLWINDOWPOS3DVMESAPROC glWindowPos3dvMESA;
PFNGLWINDOWPOS3FMESAPROC glWindowPos3fMESA;
PFNGLWINDOWPOS3FVMESAPROC glWindowPos3fvMESA;
PFNGLWINDOWPOS3IMESAPROC glWindowPos3iMESA;
PFNGLWINDOWPOS3IVMESAPROC glWindowPos3ivMESA;
PFNGLWINDOWPOS3SMESAPROC glWindowPos3sMESA;
PFNGLWINDOWPOS3SVMESAPROC glWindowPos3svMESA;
PFNGLWINDOWPOS4DMESAPROC glWindowPos4dMESA;
PFNGLWINDOWPOS4DVMESAPROC glWindowPos4dvMESA;
PFNGLWINDOWPOS4FMESAPROC glWindowPos4fMESA;
PFNGLWINDOWPOS4FVMESAPROC glWindowPos4fvMESA;
PFNGLWINDOWPOS4IMESAPROC glWindowPos4iMESA;
PFNGLWINDOWPOS4IVMESAPROC glWindowPos4ivMESA;
PFNGLWINDOWPOS4SMESAPROC glWindowPos4sMESA;
PFNGLWINDOWPOS4SVMESAPROC glWindowPos4svMESA;
#endif		// GL_MESA_window_pos

#ifdef GL_NVX_conditional_render
PFNGLBEGINCONDITIONALRENDERNVXPROC glBeginConditionalRenderNVX;
PFNGLENDCONDITIONALRENDERNVXPROC glEndConditionalRenderNVX;
#endif		// GL_NVX_conditional_render

#ifdef GL_NV_bindless_multi_draw_indirect
PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC glMultiDrawArraysIndirectBindlessNV;
PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC glMultiDrawElementsIndirectBindlessNV;
#endif		// GL_NV_bindless_multi_draw_indirect

#ifdef GL_NV_bindless_multi_draw_indirect_count
PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC glMultiDrawArraysIndirectBindlessCountNV;
PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC glMultiDrawElementsIndirectBindlessCountNV;
#endif		// GL_NV_bindless_multi_draw_indirect_count

#ifdef GL_NV_bindless_texture
PFNGLGETTEXTUREHANDLENVPROC glGetTextureHandleNV;
PFNGLGETTEXTURESAMPLERHANDLENVPROC glGetTextureSamplerHandleNV;
PFNGLMAKETEXTUREHANDLERESIDENTNVPROC glMakeTextureHandleResidentNV;
PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC glMakeTextureHandleNonResidentNV;
PFNGLGETIMAGEHANDLENVPROC glGetImageHandleNV;
PFNGLMAKEIMAGEHANDLERESIDENTNVPROC glMakeImageHandleResidentNV;
PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC glMakeImageHandleNonResidentNV;
PFNGLUNIFORMHANDLEUI64NVPROC glUniformHandleui64NV;
PFNGLUNIFORMHANDLEUI64VNVPROC glUniformHandleui64vNV;
PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC glProgramUniformHandleui64NV;
PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC glProgramUniformHandleui64vNV;
PFNGLISTEXTUREHANDLERESIDENTNVPROC glIsTextureHandleResidentNV;
PFNGLISIMAGEHANDLERESIDENTNVPROC glIsImageHandleResidentNV;
#endif		// GL_NV_bindless_texture

#ifdef GL_NV_copy_image
PFNGLCOPYIMAGESUBDATANVPROC glCopyImageSubDataNV;
#endif		// GL_NV_copy_image

#ifdef GL_NV_draw_texture
PFNGLDRAWTEXTURENVPROC glDrawTextureNV;
#endif		// GL_NV_draw_texture

#ifdef GL_NV_texture_barrier
PFNGLTEXTUREBARRIERNVPROC glTextureBarrierNV;
#endif		// GL_NV_texture_barrier

#ifdef GL_NV_vertex_attrib_integer_64bit
PFNGLVERTEXATTRIBL1I64NVPROC glVertexAttribL1i64NV;
PFNGLVERTEXATTRIBL2I64NVPROC glVertexAttribL2i64NV;
PFNGLVERTEXATTRIBL3I64NVPROC glVertexAttribL3i64NV;
PFNGLVERTEXATTRIBL4I64NVPROC glVertexAttribL4i64NV;
PFNGLVERTEXATTRIBL1I64VNVPROC glVertexAttribL1i64vNV;
PFNGLVERTEXATTRIBL2I64VNVPROC glVertexAttribL2i64vNV;
PFNGLVERTEXATTRIBL3I64VNVPROC glVertexAttribL3i64vNV;
PFNGLVERTEXATTRIBL4I64VNVPROC glVertexAttribL4i64vNV;
PFNGLVERTEXATTRIBL1UI64NVPROC glVertexAttribL1ui64NV;
PFNGLVERTEXATTRIBL2UI64NVPROC glVertexAttribL2ui64NV;
PFNGLVERTEXATTRIBL3UI64NVPROC glVertexAttribL3ui64NV;
PFNGLVERTEXATTRIBL4UI64NVPROC glVertexAttribL4ui64NV;
PFNGLVERTEXATTRIBL1UI64VNVPROC glVertexAttribL1ui64vNV;
PFNGLVERTEXATTRIBL2UI64VNVPROC glVertexAttribL2ui64vNV;
PFNGLVERTEXATTRIBL3UI64VNVPROC glVertexAttribL3ui64vNV;
PFNGLVERTEXATTRIBL4UI64VNVPROC glVertexAttribL4ui64vNV;
PFNGLGETVERTEXATTRIBLI64VNVPROC glGetVertexAttribLi64vNV;
PFNGLGETVERTEXATTRIBLUI64VNVPROC glGetVertexAttribLui64vNV;
PFNGLVERTEXATTRIBLFORMATNVPROC glVertexAttribLFormatNV;
#endif		// GL_NV_vertex_attrib_integer_64bit

#ifdef GL_OES_byte_coordinates
PFNGLMULTITEXCOORD1BOESPROC glMultiTexCoord1bOES;
PFNGLMULTITEXCOORD1BVOESPROC glMultiTexCoord1bvOES;
PFNGLMULTITEXCOORD2BOESPROC glMultiTexCoord2bOES;
PFNGLMULTITEXCOORD2BVOESPROC glMultiTexCoord2bvOES;
PFNGLMULTITEXCOORD3BOESPROC glMultiTexCoord3bOES;
PFNGLMULTITEXCOORD3BVOESPROC glMultiTexCoord3bvOES;
PFNGLMULTITEXCOORD4BOESPROC glMultiTexCoord4bOES;
PFNGLMULTITEXCOORD4BVOESPROC glMultiTexCoord4bvOES;
PFNGLTEXCOORD1BOESPROC glTexCoord1bOES;
PFNGLTEXCOORD1BVOESPROC glTexCoord1bvOES;
PFNGLTEXCOORD2BOESPROC glTexCoord2bOES;
PFNGLTEXCOORD2BVOESPROC glTexCoord2bvOES;
PFNGLTEXCOORD3BOESPROC glTexCoord3bOES;
PFNGLTEXCOORD3BVOESPROC glTexCoord3bvOES;
PFNGLTEXCOORD4BOESPROC glTexCoord4bOES;
PFNGLTEXCOORD4BVOESPROC glTexCoord4bvOES;
PFNGLVERTEX2BOESPROC glVertex2bOES;
PFNGLVERTEX2BVOESPROC glVertex2bvOES;
PFNGLVERTEX3BOESPROC glVertex3bOES;
PFNGLVERTEX3BVOESPROC glVertex3bvOES;
PFNGLVERTEX4BOESPROC glVertex4bOES;
PFNGLVERTEX4BVOESPROC glVertex4bvOES;
#endif		// GL_OES_byte_coordinates

#ifdef GL_OES_query_matrix
PFNGLQUERYMATRIXXOESPROC glQueryMatrixxOES;
#endif		// GL_OES_query_matrix

#ifdef GL_OES_single_precision
PFNGLCLEARDEPTHFOESPROC glClearDepthfOES;
PFNGLCLIPPLANEFOESPROC glClipPlanefOES;
PFNGLDEPTHRANGEFOESPROC glDepthRangefOES;
PFNGLFRUSTUMFOESPROC glFrustumfOES;
PFNGLGETCLIPPLANEFOESPROC glGetClipPlanefOES;
PFNGLORTHOFOESPROC glOrthofOES;
#endif		// GL_OES_single_precision

#ifdef GL_SGIX_flush_raster
PFNGLFLUSHRASTERSGIXPROC glFlushRasterSGIX;
#endif		// GL_SGIX_flush_raster

#ifdef GL_SGIX_igloo_interface
PFNGLIGLOOINTERFACESGIXPROC glIglooInterfaceSGIX;
#endif		// GL_SGIX_igloo_interface

#ifdef GL_SGIX_tag_sample_buffer
PFNGLTAGSAMPLEBUFFERSGIXPROC glTagSampleBufferSGIX;
#endif		// GL_SGIX_tag_sample_buffer

#ifdef GL_SUN_vertex
PFNGLCOLOR4UBVERTEX2FSUNPROC glColor4ubVertex2fSUN;
PFNGLCOLOR4UBVERTEX2FVSUNPROC glColor4ubVertex2fvSUN;
PFNGLCOLOR4UBVERTEX3FSUNPROC glColor4ubVertex3fSUN;
PFNGLCOLOR4UBVERTEX3FVSUNPROC glColor4ubVertex3fvSUN;
PFNGLCOLOR3FVERTEX3FSUNPROC glColor3fVertex3fSUN;
PFNGLCOLOR3FVERTEX3FVSUNPROC glColor3fVertex3fvSUN;
PFNGLNORMAL3FVERTEX3FSUNPROC glNormal3fVertex3fSUN;
PFNGLNORMAL3FVERTEX3FVSUNPROC glNormal3fVertex3fvSUN;
PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC glColor4fNormal3fVertex3fSUN;
PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC glColor4fNormal3fVertex3fvSUN;
PFNGLTEXCOORD2FVERTEX3FSUNPROC glTexCoord2fVertex3fSUN;
PFNGLTEXCOORD2FVERTEX3FVSUNPROC glTexCoord2fVertex3fvSUN;
PFNGLTEXCOORD4FVERTEX4FSUNPROC glTexCoord4fVertex4fSUN;
PFNGLTEXCOORD4FVERTEX4FVSUNPROC glTexCoord4fVertex4fvSUN;
PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC glTexCoord2fColor4ubVertex3fSUN;
PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC glTexCoord2fColor4ubVertex3fvSUN;
PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC glTexCoord2fColor3fVertex3fSUN;
PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC glTexCoord2fColor3fVertex3fvSUN;
PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC glTexCoord2fNormal3fVertex3fSUN;
PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC glTexCoord2fNormal3fVertex3fvSUN;
PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC glTexCoord2fColor4fNormal3fVertex3fSUN;
PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC glTexCoord2fColor4fNormal3fVertex3fvSUN;
PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC glTexCoord4fColor4fNormal3fVertex4fSUN;
PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC glTexCoord4fColor4fNormal3fVertex4fvSUN;
PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC glReplacementCodeuiVertex3fSUN;
PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC glReplacementCodeuiVertex3fvSUN;
PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC glReplacementCodeuiColor4ubVertex3fSUN;
PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC glReplacementCodeuiColor4ubVertex3fvSUN;
PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC glReplacementCodeuiColor3fVertex3fSUN;
PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC glReplacementCodeuiColor3fVertex3fvSUN;
PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC glReplacementCodeuiNormal3fVertex3fSUN;
PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiNormal3fVertex3fvSUN;
PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC glReplacementCodeuiColor4fNormal3fVertex3fSUN;
PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiColor4fNormal3fVertex3fvSUN;
PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC glReplacementCodeuiTexCoord2fVertex3fSUN;
PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC glReplacementCodeuiTexCoord2fVertex3fvSUN;
PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN;
PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN;
PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN;
PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN;
#endif		// GL_SUN_vertex

// ----- Constructors -------------------------------------------------------

CExtensionManager( void );

// ------ Destructors -------------------------------------------------------

~CExtensionManager();

// ------ Initialisation routines -------------------------------------------
void *GetGLProcAddress( char *buf );
int  StringSearch( char *pext, char *pstring );
int  CheckGLExtension(  char *pchname );
void CheckOpenGLVersion( void );
void CheckOpenGLExtensions( void );
void ExtensionInit( void );

// ----- GL extensions -----------

void Init_GL_3DFX_tbuffer( void );
void Init_GL_AMD_draw_buffers_blend( void );
void Init_GL_AMD_multi_draw_indirect( void );
void Init_GL_ARB_draw_buffers_blend( void );
void Init_GL_ARB_draw_instanced( void );
void Init_GL_ARB_window_pos( void );
void Init_GL_ATI_map_object_buffer( void );
void Init_GL_ATI_vertex_attrib_array_object( void );
void Init_GL_EXT_color_subtable( void );
void Init_GL_EXT_copy_texture( void );
void Init_GL_EXT_debug_marker( void );
void Init_GL_EXT_draw_buffers2( void );
void Init_GL_EXT_draw_instanced( void );
void Init_GL_EXT_gpu_program_parameters( void );
void Init_GL_EXT_multi_draw_arrays( void );
void Init_GL_EXT_subtexture( void );
void Init_GL_GREMEDY_frame_terminator( void );
void Init_GL_GREMEDY_string_marker( void );
void Init_GL_IBM_multimode_draw_arrays( void );
void Init_GL_INGR_blend_func_separate( void );
void Init_GL_INTEL_framebuffer_CMAA( void );
void Init_GL_MESA_resize_buffers( void );
void Init_GL_MESA_window_pos( void );
void Init_GL_NVX_conditional_render( void );
void Init_GL_NV_bindless_multi_draw_indirect( void );
void Init_GL_NV_bindless_multi_draw_indirect_count( void );
void Init_GL_NV_bindless_texture( void );
void Init_GL_NV_copy_image( void );
void Init_GL_NV_draw_texture( void );
void Init_GL_NV_texture_barrier( void );
void Init_GL_NV_vertex_attrib_integer_64bit( void );
void Init_GL_OES_byte_coordinates( void );
void Init_GL_OES_query_matrix( void );
void Init_GL_OES_single_precision( void );
void Init_GL_SGIX_flush_raster( void );
void Init_GL_SGIX_igloo_interface( void );
void Init_GL_SGIX_tag_sample_buffer( void );
void Init_GL_SUN_vertex( void );
};

#endif		// __EXTMANAGER__
