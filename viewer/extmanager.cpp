// --------------------------------------------------------------------------
// Source file for the CExtensionManager class
//
// Stored in file extmanager.cpp
//
// File:   extmanager.cpp
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
//#include "X.h"
//#include "Xlib.h"
//#include "Xutil.h"
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glxext.h>
#endif

#include "extmanager.h"

// Include this so we can read the libGL.so.1 file directly

#ifdef LOAD_LIBRARY
#include <dlfcn.h>
#endif

// --------------------------------------------------------------------------
// Default constructor
// --------------------------------------------------------------------------

CExtensionManager::CExtensionManager( void )
{
// ----- GL extensions -------

#ifdef GL_3DFX_tbuffer
	glTbufferMask3DFX = NULL;
#endif		// GL_3DFX_tbuffer

#ifdef GL_AMD_draw_buffers_blend
	glBlendFuncIndexedAMD = NULL;
	glBlendFuncSeparateIndexedAMD = NULL;
	glBlendEquationIndexedAMD = NULL;
	glBlendEquationSeparateIndexedAMD = NULL;
#endif		// GL_AMD_draw_buffers_blend

#ifdef GL_AMD_multi_draw_indirect
	glMultiDrawArraysIndirectAMD = NULL;
	glMultiDrawElementsIndirectAMD = NULL;
#endif		// GL_AMD_multi_draw_indirect

#ifdef GL_ARB_draw_buffers_blend
	glBlendEquationiARB = NULL;
	glBlendEquationSeparateiARB = NULL;
	glBlendFunciARB = NULL;
	glBlendFuncSeparateiARB = NULL;
#endif		// GL_ARB_draw_buffers_blend

#ifdef GL_ARB_draw_instanced
	glDrawArraysInstancedARB = NULL;
	glDrawElementsInstancedARB = NULL;
#endif		// GL_ARB_draw_instanced

#ifdef GL_ARB_window_pos
	glWindowPos2dARB = NULL;
	glWindowPos2dvARB = NULL;
	glWindowPos2fARB = NULL;
	glWindowPos2fvARB = NULL;
	glWindowPos2iARB = NULL;
	glWindowPos2ivARB = NULL;
	glWindowPos2sARB = NULL;
	glWindowPos2svARB = NULL;
	glWindowPos3dARB = NULL;
	glWindowPos3dvARB = NULL;
	glWindowPos3fARB = NULL;
	glWindowPos3fvARB = NULL;
	glWindowPos3iARB = NULL;
	glWindowPos3ivARB = NULL;
	glWindowPos3sARB = NULL;
	glWindowPos3svARB = NULL;
#endif		// GL_ARB_window_pos

#ifdef GL_ATI_map_object_buffer
	glMapObjectBufferATI = NULL;
	glUnmapObjectBufferATI = NULL;
#endif		// GL_ATI_map_object_buffer

#ifdef GL_ATI_vertex_attrib_array_object
	glVertexAttribArrayObjectATI = NULL;
	glGetVertexAttribArrayObjectfvATI = NULL;
	glGetVertexAttribArrayObjectivATI = NULL;
#endif		// GL_ATI_vertex_attrib_array_object

#ifdef GL_EXT_color_subtable
	glColorSubTableEXT = NULL;
	glCopyColorSubTableEXT = NULL;
#endif		// GL_EXT_color_subtable

#ifdef GL_EXT_copy_texture
	glCopyTexImage1DEXT = NULL;
	glCopyTexImage2DEXT = NULL;
	glCopyTexSubImage1DEXT = NULL;
	glCopyTexSubImage2DEXT = NULL;
	glCopyTexSubImage3DEXT = NULL;
#endif		// GL_EXT_copy_texture

#ifdef GL_EXT_debug_marker
	glInsertEventMarkerEXT = NULL;
	glPushGroupMarkerEXT = NULL;
	glPopGroupMarkerEXT = NULL;
#endif		// GL_EXT_debug_marker

#ifdef GL_EXT_draw_buffers2
	glColorMaskIndexedEXT = NULL;
#endif		// GL_EXT_draw_buffers2

#ifdef GL_EXT_draw_instanced
	glDrawArraysInstancedEXT = NULL;
	glDrawElementsInstancedEXT = NULL;
#endif		// GL_EXT_draw_instanced

#ifdef GL_EXT_gpu_program_parameters
	glProgramEnvParameters4fvEXT = NULL;
	glProgramLocalParameters4fvEXT = NULL;
#endif		// GL_EXT_gpu_program_parameters

#ifdef GL_EXT_multi_draw_arrays
	glMultiDrawArraysEXT = NULL;
	glMultiDrawElementsEXT = NULL;
#endif		// GL_EXT_multi_draw_arrays

#ifdef GL_EXT_subtexture
	glTexSubImage1DEXT = NULL;
	glTexSubImage2DEXT = NULL;
#endif		// GL_EXT_subtexture

#ifdef GL_GREMEDY_frame_terminator
	glFrameTerminatorGREMEDY = NULL;
#endif		// GL_GREMEDY_frame_terminator

#ifdef GL_GREMEDY_string_marker
	glStringMarkerGREMEDY = NULL;
#endif		// GL_GREMEDY_string_marker

#ifdef GL_IBM_multimode_draw_arrays
	glMultiModeDrawArraysIBM = NULL;
	glMultiModeDrawElementsIBM = NULL;
#endif		// GL_IBM_multimode_draw_arrays

#ifdef GL_INGR_blend_func_separate
	glBlendFuncSeparateINGR = NULL;
#endif		// GL_INGR_blend_func_separate

#ifdef GL_INTEL_framebuffer_CMAA
	glApplyFramebufferAttachmentCMAAINTEL = NULL;
#endif		// GL_INTEL_framebuffer_CMAA

#ifdef GL_MESA_resize_buffers
	glResizeBuffersMESA = NULL;
#endif		// GL_MESA_resize_buffers

#ifdef GL_MESA_window_pos
	glWindowPos2dMESA = NULL;
	glWindowPos2dvMESA = NULL;
	glWindowPos2fMESA = NULL;
	glWindowPos2fvMESA = NULL;
	glWindowPos2iMESA = NULL;
	glWindowPos2ivMESA = NULL;
	glWindowPos2sMESA = NULL;
	glWindowPos2svMESA = NULL;
	glWindowPos3dMESA = NULL;
	glWindowPos3dvMESA = NULL;
	glWindowPos3fMESA = NULL;
	glWindowPos3fvMESA = NULL;
	glWindowPos3iMESA = NULL;
	glWindowPos3ivMESA = NULL;
	glWindowPos3sMESA = NULL;
	glWindowPos3svMESA = NULL;
	glWindowPos4dMESA = NULL;
	glWindowPos4dvMESA = NULL;
	glWindowPos4fMESA = NULL;
	glWindowPos4fvMESA = NULL;
	glWindowPos4iMESA = NULL;
	glWindowPos4ivMESA = NULL;
	glWindowPos4sMESA = NULL;
	glWindowPos4svMESA = NULL;
#endif		// GL_MESA_window_pos

#ifdef GL_NVX_conditional_render
	glBeginConditionalRenderNVX = NULL;
	glEndConditionalRenderNVX = NULL;
#endif		// GL_NVX_conditional_render

#ifdef GL_NV_bindless_multi_draw_indirect
	glMultiDrawArraysIndirectBindlessNV = NULL;
	glMultiDrawElementsIndirectBindlessNV = NULL;
#endif		// GL_NV_bindless_multi_draw_indirect

#ifdef GL_NV_bindless_multi_draw_indirect_count
	glMultiDrawArraysIndirectBindlessCountNV = NULL;
	glMultiDrawElementsIndirectBindlessCountNV = NULL;
#endif		// GL_NV_bindless_multi_draw_indirect_count

#ifdef GL_NV_bindless_texture
	glGetTextureHandleNV = NULL;
	glGetTextureSamplerHandleNV = NULL;
	glMakeTextureHandleResidentNV = NULL;
	glMakeTextureHandleNonResidentNV = NULL;
	glGetImageHandleNV = NULL;
	glMakeImageHandleResidentNV = NULL;
	glMakeImageHandleNonResidentNV = NULL;
	glUniformHandleui64NV = NULL;
	glUniformHandleui64vNV = NULL;
	glProgramUniformHandleui64NV = NULL;
	glProgramUniformHandleui64vNV = NULL;
	glIsTextureHandleResidentNV = NULL;
	glIsImageHandleResidentNV = NULL;
#endif		// GL_NV_bindless_texture

#ifdef GL_NV_copy_image
	glCopyImageSubDataNV = NULL;
#endif		// GL_NV_copy_image

#ifdef GL_NV_draw_texture
	glDrawTextureNV = NULL;
#endif		// GL_NV_draw_texture

#ifdef GL_NV_texture_barrier
	glTextureBarrierNV = NULL;
#endif		// GL_NV_texture_barrier

#ifdef GL_NV_vertex_attrib_integer_64bit
	glVertexAttribL1i64NV = NULL;
	glVertexAttribL2i64NV = NULL;
	glVertexAttribL3i64NV = NULL;
	glVertexAttribL4i64NV = NULL;
	glVertexAttribL1i64vNV = NULL;
	glVertexAttribL2i64vNV = NULL;
	glVertexAttribL3i64vNV = NULL;
	glVertexAttribL4i64vNV = NULL;
	glVertexAttribL1ui64NV = NULL;
	glVertexAttribL2ui64NV = NULL;
	glVertexAttribL3ui64NV = NULL;
	glVertexAttribL4ui64NV = NULL;
	glVertexAttribL1ui64vNV = NULL;
	glVertexAttribL2ui64vNV = NULL;
	glVertexAttribL3ui64vNV = NULL;
	glVertexAttribL4ui64vNV = NULL;
	glGetVertexAttribLi64vNV = NULL;
	glGetVertexAttribLui64vNV = NULL;
	glVertexAttribLFormatNV = NULL;
#endif		// GL_NV_vertex_attrib_integer_64bit

#ifdef GL_OES_byte_coordinates
	glMultiTexCoord1bOES = NULL;
	glMultiTexCoord1bvOES = NULL;
	glMultiTexCoord2bOES = NULL;
	glMultiTexCoord2bvOES = NULL;
	glMultiTexCoord3bOES = NULL;
	glMultiTexCoord3bvOES = NULL;
	glMultiTexCoord4bOES = NULL;
	glMultiTexCoord4bvOES = NULL;
	glTexCoord1bOES = NULL;
	glTexCoord1bvOES = NULL;
	glTexCoord2bOES = NULL;
	glTexCoord2bvOES = NULL;
	glTexCoord3bOES = NULL;
	glTexCoord3bvOES = NULL;
	glTexCoord4bOES = NULL;
	glTexCoord4bvOES = NULL;
	glVertex2bOES = NULL;
	glVertex2bvOES = NULL;
	glVertex3bOES = NULL;
	glVertex3bvOES = NULL;
	glVertex4bOES = NULL;
	glVertex4bvOES = NULL;
#endif		// GL_OES_byte_coordinates

#ifdef GL_OES_query_matrix
	glQueryMatrixxOES = NULL;
#endif		// GL_OES_query_matrix

#ifdef GL_OES_single_precision
	glClearDepthfOES = NULL;
	glClipPlanefOES = NULL;
	glDepthRangefOES = NULL;
	glFrustumfOES = NULL;
	glGetClipPlanefOES = NULL;
	glOrthofOES = NULL;
#endif		// GL_OES_single_precision

#ifdef GL_SGIX_flush_raster
	glFlushRasterSGIX = NULL;
#endif		// GL_SGIX_flush_raster

#ifdef GL_SGIX_igloo_interface
	glIglooInterfaceSGIX = NULL;
#endif		// GL_SGIX_igloo_interface

#ifdef GL_SGIX_tag_sample_buffer
	glTagSampleBufferSGIX = NULL;
#endif		// GL_SGIX_tag_sample_buffer

#ifdef GL_SUN_vertex
	glColor4ubVertex2fSUN = NULL;
	glColor4ubVertex2fvSUN = NULL;
	glColor4ubVertex3fSUN = NULL;
	glColor4ubVertex3fvSUN = NULL;
	glColor3fVertex3fSUN = NULL;
	glColor3fVertex3fvSUN = NULL;
	glNormal3fVertex3fSUN = NULL;
	glNormal3fVertex3fvSUN = NULL;
	glColor4fNormal3fVertex3fSUN = NULL;
	glColor4fNormal3fVertex3fvSUN = NULL;
	glTexCoord2fVertex3fSUN = NULL;
	glTexCoord2fVertex3fvSUN = NULL;
	glTexCoord4fVertex4fSUN = NULL;
	glTexCoord4fVertex4fvSUN = NULL;
	glTexCoord2fColor4ubVertex3fSUN = NULL;
	glTexCoord2fColor4ubVertex3fvSUN = NULL;
	glTexCoord2fColor3fVertex3fSUN = NULL;
	glTexCoord2fColor3fVertex3fvSUN = NULL;
	glTexCoord2fNormal3fVertex3fSUN = NULL;
	glTexCoord2fNormal3fVertex3fvSUN = NULL;
	glTexCoord2fColor4fNormal3fVertex3fSUN = NULL;
	glTexCoord2fColor4fNormal3fVertex3fvSUN = NULL;
	glTexCoord4fColor4fNormal3fVertex4fSUN = NULL;
	glTexCoord4fColor4fNormal3fVertex4fvSUN = NULL;
	glReplacementCodeuiVertex3fSUN = NULL;
	glReplacementCodeuiVertex3fvSUN = NULL;
	glReplacementCodeuiColor4ubVertex3fSUN = NULL;
	glReplacementCodeuiColor4ubVertex3fvSUN = NULL;
	glReplacementCodeuiColor3fVertex3fSUN = NULL;
	glReplacementCodeuiColor3fVertex3fvSUN = NULL;
	glReplacementCodeuiNormal3fVertex3fSUN = NULL;
	glReplacementCodeuiNormal3fVertex3fvSUN = NULL;
	glReplacementCodeuiColor4fNormal3fVertex3fSUN = NULL;
	glReplacementCodeuiColor4fNormal3fVertex3fvSUN = NULL;
	glReplacementCodeuiTexCoord2fVertex3fSUN = NULL;
	glReplacementCodeuiTexCoord2fVertex3fvSUN = NULL;
	glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN = NULL;
	glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN = NULL;
	glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN = NULL;
	glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN = NULL;
#endif		// GL_SUN_vertex


}

// --------------------------------------------------------------------------
// Destructor
// --------------------------------------------------------------------------

CExtensionManager::~CExtensionManager( void )
{
	// ... Destructor ...
}

// ----------------------------------------------------------------------------
// Find the call address of a WGL or GLX extension function
// ----------------------------------------------------------------------------

void *CExtensionManager::GetGLProcAddress( char *buf )
{
#ifdef _WIN32
	return( wglGetProcAddress( buf ) );
#endif

#ifdef LOAD_LIBRARY
return( dlsym( m_libhandler, buf ) );
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

int CExtensionManager::StringSearch( char *pext, char *pstring )
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

int CExtensionManager::CheckGLExtension( char *pchname )
{
GLubyte *pextstring;

pextstring = (GLubyte *) glGetString(GL_EXTENSIONS);

return( StringSearch( (char *) pextstring, (char *) pchname ) );
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

void CExtensionManager::CheckOpenGLVersion( void )
{
m_OpenGL12 = CheckGLExtension( "GL_VERSION_1_2" );
m_OpenGL13 = CheckGLExtension( "GL_VERSION_1_3" );
m_OpenGL14 = CheckGLExtension( "GL_VERSION_1_4" );
m_OpenGL15 = CheckGLExtension( "GL_VERSION_1_5" );
m_OpenGL20 = CheckGLExtension( "GL_VERSION_2_0" );
m_OpenGL21 = CheckGLExtension( "GL_VERSION_2_1" );
m_OpenGL30 = CheckGLExtension( "GL_VERSION_3_0" );
m_OpenGL31 = CheckGLExtension( "GL_VERSION_3_1" );
m_OpenGL32 = CheckGLExtension( "GL_VERSION_3_2" );
m_OpenGL33 = CheckGLExtension( "GL_VERSION_3_3" );
m_OpenGL40 = CheckGLExtension( "GL_VERSION_4_0" );
m_OpenGL41 = CheckGLExtension( "GL_VERSION_4_1" );
m_OpenGL42 = CheckGLExtension( "GL_VERSION_4_2" );
m_OpenGL43 = CheckGLExtension( "GL_VERSION_4_3" );
m_OpenGL44 = CheckGLExtension( "GL_VERSION_4_4" );
m_OpenGL45 = CheckGLExtension( "GL_VERSION_4_5" );
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

void CExtensionManager::CheckOpenGLExtensions( void )
{
m_GL_3DFX_multisample = CheckGLExtension( "GL_3DFX_multisample" );
m_GL_3DFX_tbuffer = CheckGLExtension( "GL_3DFX_tbuffer" );
m_GL_3DFX_texture_compression_FXT1 = CheckGLExtension( "GL_3DFX_texture_compression_FXT1" );
m_GL_AMD_blend_minmax_factor = CheckGLExtension( "GL_AMD_blend_minmax_factor" );
m_GL_AMD_conservative_depth = CheckGLExtension( "GL_AMD_conservative_depth" );
m_GL_AMD_debug_output = CheckGLExtension( "GL_AMD_debug_output" );
m_GL_AMD_depth_clamp_separate = CheckGLExtension( "GL_AMD_depth_clamp_separate" );
m_GL_AMD_draw_buffers_blend = CheckGLExtension( "GL_AMD_draw_buffers_blend" );
m_GL_AMD_gcn_shader = CheckGLExtension( "GL_AMD_gcn_shader" );
m_GL_AMD_gpu_shader_int64 = CheckGLExtension( "GL_AMD_gpu_shader_int64" );
m_GL_AMD_interleaved_elements = CheckGLExtension( "GL_AMD_interleaved_elements" );
m_GL_AMD_multi_draw_indirect = CheckGLExtension( "GL_AMD_multi_draw_indirect" );
m_GL_AMD_name_gen_delete = CheckGLExtension( "GL_AMD_name_gen_delete" );
m_GL_AMD_occlusion_query_event = CheckGLExtension( "GL_AMD_occlusion_query_event" );
m_GL_AMD_performance_monitor = CheckGLExtension( "GL_AMD_performance_monitor" );
m_GL_AMD_pinned_memory = CheckGLExtension( "GL_AMD_pinned_memory" );
m_GL_AMD_query_buffer_object = CheckGLExtension( "GL_AMD_query_buffer_object" );
m_GL_AMD_sample_positions = CheckGLExtension( "GL_AMD_sample_positions" );
m_GL_AMD_seamless_cubemap_per_texture = CheckGLExtension( "GL_AMD_seamless_cubemap_per_texture" );
m_GL_AMD_shader_atomic_counter_ops = CheckGLExtension( "GL_AMD_shader_atomic_counter_ops" );
m_GL_AMD_shader_stencil_export = CheckGLExtension( "GL_AMD_shader_stencil_export" );
m_GL_AMD_shader_trinary_minmax = CheckGLExtension( "GL_AMD_shader_trinary_minmax" );
m_GL_AMD_sparse_texture = CheckGLExtension( "GL_AMD_sparse_texture" );
m_GL_AMD_stencil_operation_extended = CheckGLExtension( "GL_AMD_stencil_operation_extended" );
m_GL_AMD_texture_texture4 = CheckGLExtension( "GL_AMD_texture_texture4" );
m_GL_AMD_transform_feedback3_lines_triangles = CheckGLExtension( "GL_AMD_transform_feedback3_lines_triangles" );
m_GL_AMD_transform_feedback4 = CheckGLExtension( "GL_AMD_transform_feedback4" );
m_GL_AMD_vertex_shader_layer = CheckGLExtension( "GL_AMD_vertex_shader_layer" );
m_GL_AMD_vertex_shader_tessellator = CheckGLExtension( "GL_AMD_vertex_shader_tessellator" );
m_GL_AMD_vertex_shader_viewport_index = CheckGLExtension( "GL_AMD_vertex_shader_viewport_index" );
m_GL_APPLE_aux_depth_stencil = CheckGLExtension( "GL_APPLE_aux_depth_stencil" );
m_GL_APPLE_client_storage = CheckGLExtension( "GL_APPLE_client_storage" );
m_GL_APPLE_element_array = CheckGLExtension( "GL_APPLE_element_array" );
m_GL_APPLE_fence = CheckGLExtension( "GL_APPLE_fence" );
m_GL_APPLE_float_pixels = CheckGLExtension( "GL_APPLE_float_pixels" );
m_GL_APPLE_flush_buffer_range = CheckGLExtension( "GL_APPLE_flush_buffer_range" );
m_GL_APPLE_object_purgeable = CheckGLExtension( "GL_APPLE_object_purgeable" );
m_GL_APPLE_rgb_422 = CheckGLExtension( "GL_APPLE_rgb_422" );
m_GL_APPLE_row_bytes = CheckGLExtension( "GL_APPLE_row_bytes" );
m_GL_APPLE_specular_vector = CheckGLExtension( "GL_APPLE_specular_vector" );
m_GL_APPLE_texture_range = CheckGLExtension( "GL_APPLE_texture_range" );
m_GL_APPLE_transform_hint = CheckGLExtension( "GL_APPLE_transform_hint" );
m_GL_APPLE_vertex_array_object = CheckGLExtension( "GL_APPLE_vertex_array_object" );
m_GL_APPLE_vertex_array_range = CheckGLExtension( "GL_APPLE_vertex_array_range" );
m_GL_APPLE_vertex_program_evaluators = CheckGLExtension( "GL_APPLE_vertex_program_evaluators" );
m_GL_APPLE_ycbcr_422 = CheckGLExtension( "GL_APPLE_ycbcr_422" );
m_GL_ARB_ES2_compatibility = CheckGLExtension( "GL_ARB_ES2_compatibility" );
m_GL_ARB_ES3_1_compatibility = CheckGLExtension( "GL_ARB_ES3_1_compatibility" );
m_GL_ARB_ES3_2_compatibility = CheckGLExtension( "GL_ARB_ES3_2_compatibility" );
m_GL_ARB_ES3_compatibility = CheckGLExtension( "GL_ARB_ES3_compatibility" );
m_GL_ARB_arrays_of_arrays = CheckGLExtension( "GL_ARB_arrays_of_arrays" );
m_GL_ARB_base_instance = CheckGLExtension( "GL_ARB_base_instance" );
m_GL_ARB_bindless_texture = CheckGLExtension( "GL_ARB_bindless_texture" );
m_GL_ARB_blend_func_extended = CheckGLExtension( "GL_ARB_blend_func_extended" );
m_GL_ARB_buffer_storage = CheckGLExtension( "GL_ARB_buffer_storage" );
m_GL_ARB_cl_event = CheckGLExtension( "GL_ARB_cl_event" );
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
m_GL_ARB_fragment_shader_interlock = CheckGLExtension( "GL_ARB_fragment_shader_interlock" );
m_GL_ARB_framebuffer_no_attachments = CheckGLExtension( "GL_ARB_framebuffer_no_attachments" );
m_GL_ARB_framebuffer_object = CheckGLExtension( "GL_ARB_framebuffer_object" );
m_GL_ARB_framebuffer_sRGB = CheckGLExtension( "GL_ARB_framebuffer_sRGB" );
m_GL_ARB_geometry_shader4 = CheckGLExtension( "GL_ARB_geometry_shader4" );
m_GL_ARB_get_program_binary = CheckGLExtension( "GL_ARB_get_program_binary" );
m_GL_ARB_get_texture_sub_image = CheckGLExtension( "GL_ARB_get_texture_sub_image" );
m_GL_ARB_gpu_shader5 = CheckGLExtension( "GL_ARB_gpu_shader5" );
m_GL_ARB_gpu_shader_fp64 = CheckGLExtension( "GL_ARB_gpu_shader_fp64" );
m_GL_ARB_gpu_shader_int64 = CheckGLExtension( "GL_ARB_gpu_shader_int64" );
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
m_GL_ARB_matrix_palette = CheckGLExtension( "GL_ARB_matrix_palette" );
m_GL_ARB_multi_bind = CheckGLExtension( "GL_ARB_multi_bind" );
m_GL_ARB_multi_draw_indirect = CheckGLExtension( "GL_ARB_multi_draw_indirect" );
m_GL_ARB_multisample = CheckGLExtension( "GL_ARB_multisample" );
m_GL_ARB_multitexture = CheckGLExtension( "GL_ARB_multitexture" );
m_GL_ARB_occlusion_query = CheckGLExtension( "GL_ARB_occlusion_query" );
m_GL_ARB_occlusion_query2 = CheckGLExtension( "GL_ARB_occlusion_query2" );
m_GL_ARB_parallel_shader_compile = CheckGLExtension( "GL_ARB_parallel_shader_compile" );
m_GL_ARB_pipeline_statistics_query = CheckGLExtension( "GL_ARB_pipeline_statistics_query" );
m_GL_ARB_pixel_buffer_object = CheckGLExtension( "GL_ARB_pixel_buffer_object" );
m_GL_ARB_point_parameters = CheckGLExtension( "GL_ARB_point_parameters" );
m_GL_ARB_point_sprite = CheckGLExtension( "GL_ARB_point_sprite" );
m_GL_ARB_post_depth_coverage = CheckGLExtension( "GL_ARB_post_depth_coverage" );
m_GL_ARB_program_interface_query = CheckGLExtension( "GL_ARB_program_interface_query" );
m_GL_ARB_provoking_vertex = CheckGLExtension( "GL_ARB_provoking_vertex" );
m_GL_ARB_query_buffer_object = CheckGLExtension( "GL_ARB_query_buffer_object" );
m_GL_ARB_robust_buffer_access_behavior = CheckGLExtension( "GL_ARB_robust_buffer_access_behavior" );
m_GL_ARB_robustness = CheckGLExtension( "GL_ARB_robustness" );
m_GL_ARB_robustness_isolation = CheckGLExtension( "GL_ARB_robustness_isolation" );
m_GL_ARB_sample_locations = CheckGLExtension( "GL_ARB_sample_locations" );
m_GL_ARB_sample_shading = CheckGLExtension( "GL_ARB_sample_shading" );
m_GL_ARB_sampler_objects = CheckGLExtension( "GL_ARB_sampler_objects" );
m_GL_ARB_seamless_cube_map = CheckGLExtension( "GL_ARB_seamless_cube_map" );
m_GL_ARB_seamless_cubemap_per_texture = CheckGLExtension( "GL_ARB_seamless_cubemap_per_texture" );
m_GL_ARB_separate_shader_objects = CheckGLExtension( "GL_ARB_separate_shader_objects" );
m_GL_ARB_shader_atomic_counter_ops = CheckGLExtension( "GL_ARB_shader_atomic_counter_ops" );
m_GL_ARB_shader_atomic_counters = CheckGLExtension( "GL_ARB_shader_atomic_counters" );
m_GL_ARB_shader_ballot = CheckGLExtension( "GL_ARB_shader_ballot" );
m_GL_ARB_shader_bit_encoding = CheckGLExtension( "GL_ARB_shader_bit_encoding" );
m_GL_ARB_shader_clock = CheckGLExtension( "GL_ARB_shader_clock" );
m_GL_ARB_shader_draw_parameters = CheckGLExtension( "GL_ARB_shader_draw_parameters" );
m_GL_ARB_shader_group_vote = CheckGLExtension( "GL_ARB_shader_group_vote" );
m_GL_ARB_shader_image_load_store = CheckGLExtension( "GL_ARB_shader_image_load_store" );
m_GL_ARB_shader_image_size = CheckGLExtension( "GL_ARB_shader_image_size" );
m_GL_ARB_shader_objects = CheckGLExtension( "GL_ARB_shader_objects" );
m_GL_ARB_shader_precision = CheckGLExtension( "GL_ARB_shader_precision" );
m_GL_ARB_shader_stencil_export = CheckGLExtension( "GL_ARB_shader_stencil_export" );
m_GL_ARB_shader_storage_buffer_object = CheckGLExtension( "GL_ARB_shader_storage_buffer_object" );
m_GL_ARB_shader_subroutine = CheckGLExtension( "GL_ARB_shader_subroutine" );
m_GL_ARB_shader_texture_image_samples = CheckGLExtension( "GL_ARB_shader_texture_image_samples" );
m_GL_ARB_shader_texture_lod = CheckGLExtension( "GL_ARB_shader_texture_lod" );
m_GL_ARB_shader_viewport_layer_array = CheckGLExtension( "GL_ARB_shader_viewport_layer_array" );
m_GL_ARB_shading_language_100 = CheckGLExtension( "GL_ARB_shading_language_100" );
m_GL_ARB_shading_language_420pack = CheckGLExtension( "GL_ARB_shading_language_420pack" );
m_GL_ARB_shading_language_include = CheckGLExtension( "GL_ARB_shading_language_include" );
m_GL_ARB_shading_language_packing = CheckGLExtension( "GL_ARB_shading_language_packing" );
m_GL_ARB_shadow = CheckGLExtension( "GL_ARB_shadow" );
m_GL_ARB_shadow_ambient = CheckGLExtension( "GL_ARB_shadow_ambient" );
m_GL_ARB_sparse_buffer = CheckGLExtension( "GL_ARB_sparse_buffer" );
m_GL_ARB_sparse_texture = CheckGLExtension( "GL_ARB_sparse_texture" );
m_GL_ARB_sparse_texture2 = CheckGLExtension( "GL_ARB_sparse_texture2" );
m_GL_ARB_sparse_texture_clamp = CheckGLExtension( "GL_ARB_sparse_texture_clamp" );
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
m_GL_ARB_texture_filter_minmax = CheckGLExtension( "GL_ARB_texture_filter_minmax" );
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
m_GL_ARB_vertex_blend = CheckGLExtension( "GL_ARB_vertex_blend" );
m_GL_ARB_vertex_buffer_object = CheckGLExtension( "GL_ARB_vertex_buffer_object" );
m_GL_ARB_vertex_program = CheckGLExtension( "GL_ARB_vertex_program" );
m_GL_ARB_vertex_shader = CheckGLExtension( "GL_ARB_vertex_shader" );
m_GL_ARB_vertex_type_10f_11f_11f_rev = CheckGLExtension( "GL_ARB_vertex_type_10f_11f_11f_rev" );
m_GL_ARB_vertex_type_2_10_10_10_rev = CheckGLExtension( "GL_ARB_vertex_type_2_10_10_10_rev" );
m_GL_ARB_viewport_array = CheckGLExtension( "GL_ARB_viewport_array" );
m_GL_ARB_window_pos = CheckGLExtension( "GL_ARB_window_pos" );
m_GL_ATI_draw_buffers = CheckGLExtension( "GL_ATI_draw_buffers" );
m_GL_ATI_element_array = CheckGLExtension( "GL_ATI_element_array" );
m_GL_ATI_envmap_bumpmap = CheckGLExtension( "GL_ATI_envmap_bumpmap" );
m_GL_ATI_fragment_shader = CheckGLExtension( "GL_ATI_fragment_shader" );
m_GL_ATI_map_object_buffer = CheckGLExtension( "GL_ATI_map_object_buffer" );
m_GL_ATI_meminfo = CheckGLExtension( "GL_ATI_meminfo" );
m_GL_ATI_pixel_format_float = CheckGLExtension( "GL_ATI_pixel_format_float" );
m_GL_ATI_pn_triangles = CheckGLExtension( "GL_ATI_pn_triangles" );
m_GL_ATI_separate_stencil = CheckGLExtension( "GL_ATI_separate_stencil" );
m_GL_ATI_text_fragment_shader = CheckGLExtension( "GL_ATI_text_fragment_shader" );
m_GL_ATI_texture_env_combine3 = CheckGLExtension( "GL_ATI_texture_env_combine3" );
m_GL_ATI_texture_float = CheckGLExtension( "GL_ATI_texture_float" );
m_GL_ATI_texture_mirror_once = CheckGLExtension( "GL_ATI_texture_mirror_once" );
m_GL_ATI_vertex_array_object = CheckGLExtension( "GL_ATI_vertex_array_object" );
m_GL_ATI_vertex_attrib_array_object = CheckGLExtension( "GL_ATI_vertex_attrib_array_object" );
m_GL_ATI_vertex_streams = CheckGLExtension( "GL_ATI_vertex_streams" );
m_GL_EXT_422_pixels = CheckGLExtension( "GL_EXT_422_pixels" );
m_GL_EXT_abgr = CheckGLExtension( "GL_EXT_abgr" );
m_GL_EXT_bgra = CheckGLExtension( "GL_EXT_bgra" );
m_GL_EXT_bindable_uniform = CheckGLExtension( "GL_EXT_bindable_uniform" );
m_GL_EXT_blend_color = CheckGLExtension( "GL_EXT_blend_color" );
m_GL_EXT_blend_equation_separate = CheckGLExtension( "GL_EXT_blend_equation_separate" );
m_GL_EXT_blend_func_separate = CheckGLExtension( "GL_EXT_blend_func_separate" );
m_GL_EXT_blend_logic_op = CheckGLExtension( "GL_EXT_blend_logic_op" );
m_GL_EXT_blend_minmax = CheckGLExtension( "GL_EXT_blend_minmax" );
m_GL_EXT_blend_subtract = CheckGLExtension( "GL_EXT_blend_subtract" );
m_GL_EXT_clip_volume_hint = CheckGLExtension( "GL_EXT_clip_volume_hint" );
m_GL_EXT_cmyka = CheckGLExtension( "GL_EXT_cmyka" );
m_GL_EXT_color_subtable = CheckGLExtension( "GL_EXT_color_subtable" );
m_GL_EXT_compiled_vertex_array = CheckGLExtension( "GL_EXT_compiled_vertex_array" );
m_GL_EXT_convolution = CheckGLExtension( "GL_EXT_convolution" );
m_GL_EXT_coordinate_frame = CheckGLExtension( "GL_EXT_coordinate_frame" );
m_GL_EXT_copy_texture = CheckGLExtension( "GL_EXT_copy_texture" );
m_GL_EXT_cull_vertex = CheckGLExtension( "GL_EXT_cull_vertex" );
m_GL_EXT_debug_label = CheckGLExtension( "GL_EXT_debug_label" );
m_GL_EXT_debug_marker = CheckGLExtension( "GL_EXT_debug_marker" );
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
m_GL_EXT_histogram = CheckGLExtension( "GL_EXT_histogram" );
m_GL_EXT_index_array_formats = CheckGLExtension( "GL_EXT_index_array_formats" );
m_GL_EXT_index_func = CheckGLExtension( "GL_EXT_index_func" );
m_GL_EXT_index_material = CheckGLExtension( "GL_EXT_index_material" );
m_GL_EXT_index_texture = CheckGLExtension( "GL_EXT_index_texture" );
m_GL_EXT_light_texture = CheckGLExtension( "GL_EXT_light_texture" );
m_GL_EXT_misc_attribute = CheckGLExtension( "GL_EXT_misc_attribute" );
m_GL_EXT_multi_draw_arrays = CheckGLExtension( "GL_EXT_multi_draw_arrays" );
m_GL_EXT_multisample = CheckGLExtension( "GL_EXT_multisample" );
m_GL_EXT_packed_depth_stencil = CheckGLExtension( "GL_EXT_packed_depth_stencil" );
m_GL_EXT_packed_float = CheckGLExtension( "GL_EXT_packed_float" );
m_GL_EXT_packed_pixels = CheckGLExtension( "GL_EXT_packed_pixels" );
m_GL_EXT_paletted_texture = CheckGLExtension( "GL_EXT_paletted_texture" );
m_GL_EXT_pixel_buffer_object = CheckGLExtension( "GL_EXT_pixel_buffer_object" );
m_GL_EXT_pixel_transform = CheckGLExtension( "GL_EXT_pixel_transform" );
m_GL_EXT_pixel_transform_color_table = CheckGLExtension( "GL_EXT_pixel_transform_color_table" );
m_GL_EXT_point_parameters = CheckGLExtension( "GL_EXT_point_parameters" );
m_GL_EXT_polygon_offset = CheckGLExtension( "GL_EXT_polygon_offset" );
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
m_GL_EXT_shared_texture_palette = CheckGLExtension( "GL_EXT_shared_texture_palette" );
m_GL_EXT_sparse_texture2 = CheckGLExtension( "GL_EXT_sparse_texture2" );
m_GL_EXT_stencil_clear_tag = CheckGLExtension( "GL_EXT_stencil_clear_tag" );
m_GL_EXT_stencil_two_side = CheckGLExtension( "GL_EXT_stencil_two_side" );
m_GL_EXT_stencil_wrap = CheckGLExtension( "GL_EXT_stencil_wrap" );
m_GL_EXT_subtexture = CheckGLExtension( "GL_EXT_subtexture" );
m_GL_EXT_texture = CheckGLExtension( "GL_EXT_texture" );
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
m_GL_EXT_texture_perturb_normal = CheckGLExtension( "GL_EXT_texture_perturb_normal" );
m_GL_EXT_texture_sRGB = CheckGLExtension( "GL_EXT_texture_sRGB" );
m_GL_EXT_texture_sRGB_decode = CheckGLExtension( "GL_EXT_texture_sRGB_decode" );
m_GL_EXT_texture_shared_exponent = CheckGLExtension( "GL_EXT_texture_shared_exponent" );
m_GL_EXT_texture_snorm = CheckGLExtension( "GL_EXT_texture_snorm" );
m_GL_EXT_texture_swizzle = CheckGLExtension( "GL_EXT_texture_swizzle" );
m_GL_EXT_timer_query = CheckGLExtension( "GL_EXT_timer_query" );
m_GL_EXT_transform_feedback = CheckGLExtension( "GL_EXT_transform_feedback" );
m_GL_EXT_vertex_array = CheckGLExtension( "GL_EXT_vertex_array" );
m_GL_EXT_vertex_array_bgra = CheckGLExtension( "GL_EXT_vertex_array_bgra" );
m_GL_EXT_vertex_attrib_64bit = CheckGLExtension( "GL_EXT_vertex_attrib_64bit" );
m_GL_EXT_vertex_shader = CheckGLExtension( "GL_EXT_vertex_shader" );
m_GL_EXT_vertex_weighting = CheckGLExtension( "GL_EXT_vertex_weighting" );
m_GL_EXT_x11_sync_object = CheckGLExtension( "GL_EXT_x11_sync_object" );
m_GL_GREMEDY_frame_terminator = CheckGLExtension( "GL_GREMEDY_frame_terminator" );
m_GL_GREMEDY_string_marker = CheckGLExtension( "GL_GREMEDY_string_marker" );
m_GL_HP_convolution_border_modes = CheckGLExtension( "GL_HP_convolution_border_modes" );
m_GL_HP_image_transform = CheckGLExtension( "GL_HP_image_transform" );
m_GL_HP_occlusion_test = CheckGLExtension( "GL_HP_occlusion_test" );
m_GL_HP_texture_lighting = CheckGLExtension( "GL_HP_texture_lighting" );
m_GL_IBM_cull_vertex = CheckGLExtension( "GL_IBM_cull_vertex" );
m_GL_IBM_multimode_draw_arrays = CheckGLExtension( "GL_IBM_multimode_draw_arrays" );
m_GL_IBM_rasterpos_clip = CheckGLExtension( "GL_IBM_rasterpos_clip" );
m_GL_IBM_static_data = CheckGLExtension( "GL_IBM_static_data" );
m_GL_IBM_texture_mirrored_repeat = CheckGLExtension( "GL_IBM_texture_mirrored_repeat" );
m_GL_IBM_vertex_array_lists = CheckGLExtension( "GL_IBM_vertex_array_lists" );
m_GL_INGR_blend_func_separate = CheckGLExtension( "GL_INGR_blend_func_separate" );
m_GL_INGR_color_clamp = CheckGLExtension( "GL_INGR_color_clamp" );
m_GL_INGR_interlace_read = CheckGLExtension( "GL_INGR_interlace_read" );
m_GL_INTEL_fragment_shader_ordering = CheckGLExtension( "GL_INTEL_fragment_shader_ordering" );
m_GL_INTEL_framebuffer_CMAA = CheckGLExtension( "GL_INTEL_framebuffer_CMAA" );
m_GL_INTEL_map_texture = CheckGLExtension( "GL_INTEL_map_texture" );
m_GL_INTEL_parallel_arrays = CheckGLExtension( "GL_INTEL_parallel_arrays" );
m_GL_INTEL_performance_query = CheckGLExtension( "GL_INTEL_performance_query" );
m_GL_KHR_blend_equation_advanced = CheckGLExtension( "GL_KHR_blend_equation_advanced" );
m_GL_KHR_blend_equation_advanced_coherent = CheckGLExtension( "GL_KHR_blend_equation_advanced_coherent" );
m_GL_KHR_context_flush_control = CheckGLExtension( "GL_KHR_context_flush_control" );
m_GL_KHR_debug = CheckGLExtension( "GL_KHR_debug" );
m_GL_KHR_no_error = CheckGLExtension( "GL_KHR_no_error" );
m_GL_KHR_robust_buffer_access_behavior = CheckGLExtension( "GL_KHR_robust_buffer_access_behavior" );
m_GL_KHR_robustness = CheckGLExtension( "GL_KHR_robustness" );
m_GL_KHR_texture_compression_astc_hdr = CheckGLExtension( "GL_KHR_texture_compression_astc_hdr" );
m_GL_KHR_texture_compression_astc_ldr = CheckGLExtension( "GL_KHR_texture_compression_astc_ldr" );
m_GL_KHR_texture_compression_astc_sliced_3d = CheckGLExtension( "GL_KHR_texture_compression_astc_sliced_3d" );
m_GL_MESAX_texture_stack = CheckGLExtension( "GL_MESAX_texture_stack" );
m_GL_MESA_pack_invert = CheckGLExtension( "GL_MESA_pack_invert" );
m_GL_MESA_resize_buffers = CheckGLExtension( "GL_MESA_resize_buffers" );
m_GL_MESA_window_pos = CheckGLExtension( "GL_MESA_window_pos" );
m_GL_MESA_ycbcr_texture = CheckGLExtension( "GL_MESA_ycbcr_texture" );
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
m_GL_NV_deep_texture3D = CheckGLExtension( "GL_NV_deep_texture3D" );
m_GL_NV_depth_buffer_float = CheckGLExtension( "GL_NV_depth_buffer_float" );
m_GL_NV_depth_clamp = CheckGLExtension( "GL_NV_depth_clamp" );
m_GL_NV_draw_texture = CheckGLExtension( "GL_NV_draw_texture" );
m_GL_NV_evaluators = CheckGLExtension( "GL_NV_evaluators" );
m_GL_NV_explicit_multisample = CheckGLExtension( "GL_NV_explicit_multisample" );
m_GL_NV_fence = CheckGLExtension( "GL_NV_fence" );
m_GL_NV_fill_rectangle = CheckGLExtension( "GL_NV_fill_rectangle" );
m_GL_NV_float_buffer = CheckGLExtension( "GL_NV_float_buffer" );
m_GL_NV_fog_distance = CheckGLExtension( "GL_NV_fog_distance" );
m_GL_NV_fragment_coverage_to_color = CheckGLExtension( "GL_NV_fragment_coverage_to_color" );
m_GL_NV_fragment_program = CheckGLExtension( "GL_NV_fragment_program" );
m_GL_NV_fragment_program2 = CheckGLExtension( "GL_NV_fragment_program2" );
m_GL_NV_fragment_program4 = CheckGLExtension( "GL_NV_fragment_program4" );
m_GL_NV_fragment_program_option = CheckGLExtension( "GL_NV_fragment_program_option" );
m_GL_NV_fragment_shader_interlock = CheckGLExtension( "GL_NV_fragment_shader_interlock" );
m_GL_NV_framebuffer_mixed_samples = CheckGLExtension( "GL_NV_framebuffer_mixed_samples" );
m_GL_NV_framebuffer_multisample_coverage = CheckGLExtension( "GL_NV_framebuffer_multisample_coverage" );
m_GL_NV_geometry_program4 = CheckGLExtension( "GL_NV_geometry_program4" );
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
m_GL_NV_present_video = CheckGLExtension( "GL_NV_present_video" );
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
m_GL_NV_shader_buffer_store = CheckGLExtension( "GL_NV_shader_buffer_store" );
m_GL_NV_shader_storage_buffer_object = CheckGLExtension( "GL_NV_shader_storage_buffer_object" );
m_GL_NV_shader_thread_group = CheckGLExtension( "GL_NV_shader_thread_group" );
m_GL_NV_shader_thread_shuffle = CheckGLExtension( "GL_NV_shader_thread_shuffle" );
m_GL_NV_tessellation_program5 = CheckGLExtension( "GL_NV_tessellation_program5" );
m_GL_NV_texgen_emboss = CheckGLExtension( "GL_NV_texgen_emboss" );
m_GL_NV_texgen_reflection = CheckGLExtension( "GL_NV_texgen_reflection" );
m_GL_NV_texture_barrier = CheckGLExtension( "GL_NV_texture_barrier" );
m_GL_NV_texture_compression_vtc = CheckGLExtension( "GL_NV_texture_compression_vtc" );
m_GL_NV_texture_env_combine4 = CheckGLExtension( "GL_NV_texture_env_combine4" );
m_GL_NV_texture_expand_normal = CheckGLExtension( "GL_NV_texture_expand_normal" );
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
m_GL_NV_vertex_program4 = CheckGLExtension( "GL_NV_vertex_program4" );
m_GL_NV_video_capture = CheckGLExtension( "GL_NV_video_capture" );
m_GL_NV_viewport_array2 = CheckGLExtension( "GL_NV_viewport_array2" );
m_GL_OES_byte_coordinates = CheckGLExtension( "GL_OES_byte_coordinates" );
m_GL_OES_compressed_paletted_texture = CheckGLExtension( "GL_OES_compressed_paletted_texture" );
m_GL_OES_fixed_point = CheckGLExtension( "GL_OES_fixed_point" );
m_GL_OES_query_matrix = CheckGLExtension( "GL_OES_query_matrix" );
m_GL_OES_read_format = CheckGLExtension( "GL_OES_read_format" );
m_GL_OES_single_precision = CheckGLExtension( "GL_OES_single_precision" );
m_GL_OML_interlace = CheckGLExtension( "GL_OML_interlace" );
m_GL_OML_resample = CheckGLExtension( "GL_OML_resample" );
m_GL_OML_subsample = CheckGLExtension( "GL_OML_subsample" );
m_GL_OVR_multiview = CheckGLExtension( "GL_OVR_multiview" );
m_GL_OVR_multiview2 = CheckGLExtension( "GL_OVR_multiview2" );
m_GL_PGI_misc_hints = CheckGLExtension( "GL_PGI_misc_hints" );
m_GL_PGI_vertex_hints = CheckGLExtension( "GL_PGI_vertex_hints" );
m_GL_REND_screen_coordinates = CheckGLExtension( "GL_REND_screen_coordinates" );
m_GL_S3_s3tc = CheckGLExtension( "GL_S3_s3tc" );
m_GL_SGIS_detail_texture = CheckGLExtension( "GL_SGIS_detail_texture" );
m_GL_SGIS_fog_function = CheckGLExtension( "GL_SGIS_fog_function" );
m_GL_SGIS_generate_mipmap = CheckGLExtension( "GL_SGIS_generate_mipmap" );
m_GL_SGIS_multisample = CheckGLExtension( "GL_SGIS_multisample" );
m_GL_SGIS_pixel_texture = CheckGLExtension( "GL_SGIS_pixel_texture" );
m_GL_SGIS_point_line_texgen = CheckGLExtension( "GL_SGIS_point_line_texgen" );
m_GL_SGIS_point_parameters = CheckGLExtension( "GL_SGIS_point_parameters" );
m_GL_SGIS_sharpen_texture = CheckGLExtension( "GL_SGIS_sharpen_texture" );
m_GL_SGIS_texture4D = CheckGLExtension( "GL_SGIS_texture4D" );
m_GL_SGIS_texture_border_clamp = CheckGLExtension( "GL_SGIS_texture_border_clamp" );
m_GL_SGIS_texture_color_mask = CheckGLExtension( "GL_SGIS_texture_color_mask" );
m_GL_SGIS_texture_edge_clamp = CheckGLExtension( "GL_SGIS_texture_edge_clamp" );
m_GL_SGIS_texture_filter4 = CheckGLExtension( "GL_SGIS_texture_filter4" );
m_GL_SGIS_texture_lod = CheckGLExtension( "GL_SGIS_texture_lod" );
m_GL_SGIS_texture_select = CheckGLExtension( "GL_SGIS_texture_select" );
m_GL_SGIX_async = CheckGLExtension( "GL_SGIX_async" );
m_GL_SGIX_async_histogram = CheckGLExtension( "GL_SGIX_async_histogram" );
m_GL_SGIX_async_pixel = CheckGLExtension( "GL_SGIX_async_pixel" );
m_GL_SGIX_blend_alpha_minmax = CheckGLExtension( "GL_SGIX_blend_alpha_minmax" );
m_GL_SGIX_calligraphic_fragment = CheckGLExtension( "GL_SGIX_calligraphic_fragment" );
m_GL_SGIX_clipmap = CheckGLExtension( "GL_SGIX_clipmap" );
m_GL_SGIX_convolution_accuracy = CheckGLExtension( "GL_SGIX_convolution_accuracy" );
m_GL_SGIX_depth_pass_instrument = CheckGLExtension( "GL_SGIX_depth_pass_instrument" );
m_GL_SGIX_depth_texture = CheckGLExtension( "GL_SGIX_depth_texture" );
m_GL_SGIX_flush_raster = CheckGLExtension( "GL_SGIX_flush_raster" );
m_GL_SGIX_fog_offset = CheckGLExtension( "GL_SGIX_fog_offset" );
m_GL_SGIX_fragment_lighting = CheckGLExtension( "GL_SGIX_fragment_lighting" );
m_GL_SGIX_framezoom = CheckGLExtension( "GL_SGIX_framezoom" );
m_GL_SGIX_igloo_interface = CheckGLExtension( "GL_SGIX_igloo_interface" );
m_GL_SGIX_instruments = CheckGLExtension( "GL_SGIX_instruments" );
m_GL_SGIX_interlace = CheckGLExtension( "GL_SGIX_interlace" );
m_GL_SGIX_ir_instrument1 = CheckGLExtension( "GL_SGIX_ir_instrument1" );
m_GL_SGIX_list_priority = CheckGLExtension( "GL_SGIX_list_priority" );
m_GL_SGIX_pixel_texture = CheckGLExtension( "GL_SGIX_pixel_texture" );
m_GL_SGIX_pixel_tiles = CheckGLExtension( "GL_SGIX_pixel_tiles" );
m_GL_SGIX_polynomial_ffd = CheckGLExtension( "GL_SGIX_polynomial_ffd" );
m_GL_SGIX_reference_plane = CheckGLExtension( "GL_SGIX_reference_plane" );
m_GL_SGIX_resample = CheckGLExtension( "GL_SGIX_resample" );
m_GL_SGIX_scalebias_hint = CheckGLExtension( "GL_SGIX_scalebias_hint" );
m_GL_SGIX_shadow = CheckGLExtension( "GL_SGIX_shadow" );
m_GL_SGIX_shadow_ambient = CheckGLExtension( "GL_SGIX_shadow_ambient" );
m_GL_SGIX_sprite = CheckGLExtension( "GL_SGIX_sprite" );
m_GL_SGIX_subsample = CheckGLExtension( "GL_SGIX_subsample" );
m_GL_SGIX_tag_sample_buffer = CheckGLExtension( "GL_SGIX_tag_sample_buffer" );
m_GL_SGIX_texture_add_env = CheckGLExtension( "GL_SGIX_texture_add_env" );
m_GL_SGIX_texture_coordinate_clamp = CheckGLExtension( "GL_SGIX_texture_coordinate_clamp" );
m_GL_SGIX_texture_lod_bias = CheckGLExtension( "GL_SGIX_texture_lod_bias" );
m_GL_SGIX_texture_multi_buffer = CheckGLExtension( "GL_SGIX_texture_multi_buffer" );
m_GL_SGIX_texture_scale_bias = CheckGLExtension( "GL_SGIX_texture_scale_bias" );
m_GL_SGIX_vertex_preclip = CheckGLExtension( "GL_SGIX_vertex_preclip" );
m_GL_SGIX_ycrcb = CheckGLExtension( "GL_SGIX_ycrcb" );
m_GL_SGIX_ycrcb_subsample = CheckGLExtension( "GL_SGIX_ycrcb_subsample" );
m_GL_SGIX_ycrcba = CheckGLExtension( "GL_SGIX_ycrcba" );
m_GL_SGI_color_matrix = CheckGLExtension( "GL_SGI_color_matrix" );
m_GL_SGI_color_table = CheckGLExtension( "GL_SGI_color_table" );
m_GL_SGI_texture_color_table = CheckGLExtension( "GL_SGI_texture_color_table" );
m_GL_SUNX_constant_data = CheckGLExtension( "GL_SUNX_constant_data" );
m_GL_SUN_convolution_border_modes = CheckGLExtension( "GL_SUN_convolution_border_modes" );
m_GL_SUN_global_alpha = CheckGLExtension( "GL_SUN_global_alpha" );
m_GL_SUN_mesh_array = CheckGLExtension( "GL_SUN_mesh_array" );
m_GL_SUN_slice_accum = CheckGLExtension( "GL_SUN_slice_accum" );
m_GL_SUN_triangle_list = CheckGLExtension( "GL_SUN_triangle_list" );
m_GL_SUN_vertex = CheckGLExtension( "GL_SUN_vertex" );
m_GL_VERSION_1_2 = CheckGLExtension( "GL_VERSION_1_2" );
m_GL_VERSION_1_3 = CheckGLExtension( "GL_VERSION_1_3" );
m_GL_VERSION_1_4 = CheckGLExtension( "GL_VERSION_1_4" );
m_GL_VERSION_1_5 = CheckGLExtension( "GL_VERSION_1_5" );
m_GL_VERSION_2_0 = CheckGLExtension( "GL_VERSION_2_0" );
m_GL_VERSION_2_1 = CheckGLExtension( "GL_VERSION_2_1" );
m_GL_VERSION_3_0 = CheckGLExtension( "GL_VERSION_3_0" );
m_GL_VERSION_3_1 = CheckGLExtension( "GL_VERSION_3_1" );
m_GL_VERSION_3_2 = CheckGLExtension( "GL_VERSION_3_2" );
m_GL_VERSION_3_3 = CheckGLExtension( "GL_VERSION_3_3" );
m_GL_VERSION_4_0 = CheckGLExtension( "GL_VERSION_4_0" );
m_GL_VERSION_4_1 = CheckGLExtension( "GL_VERSION_4_1" );
m_GL_VERSION_4_2 = CheckGLExtension( "GL_VERSION_4_2" );
m_GL_VERSION_4_3 = CheckGLExtension( "GL_VERSION_4_3" );
m_GL_VERSION_4_4 = CheckGLExtension( "GL_VERSION_4_4" );
m_GL_VERSION_4_5 = CheckGLExtension( "GL_VERSION_4_5" );
m_GL_WIN_phong_shading = CheckGLExtension( "GL_WIN_phong_shading" );
m_GL_WIN_specular_fog = CheckGLExtension( "GL_WIN_specular_fog" );
}

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

void CExtensionManager::ExtensionInit( void )
{
#ifdef LOAD_LIBRARY
m_libhandler = dlopen( "/usr/lib/libGL.so.1", RTLD_NOW | RTLD_GLOBAL );
// printf( "Opened handler = %08X\n", (unsigned int) m_libhandler );
#endif

CheckOpenGLVersion();
CheckOpenGLExtensions();

Init_GL_3DFX_tbuffer();
Init_GL_AMD_draw_buffers_blend();
Init_GL_AMD_multi_draw_indirect();
Init_GL_ARB_draw_buffers_blend();
Init_GL_ARB_draw_instanced();
Init_GL_ARB_window_pos();
Init_GL_ATI_map_object_buffer();
Init_GL_ATI_vertex_attrib_array_object();
Init_GL_EXT_color_subtable();
Init_GL_EXT_copy_texture();
Init_GL_EXT_debug_marker();
Init_GL_EXT_draw_buffers2();
Init_GL_EXT_draw_instanced();
Init_GL_EXT_gpu_program_parameters();
Init_GL_EXT_multi_draw_arrays();
Init_GL_EXT_subtexture();
Init_GL_GREMEDY_frame_terminator();
Init_GL_GREMEDY_string_marker();
Init_GL_IBM_multimode_draw_arrays();
Init_GL_INGR_blend_func_separate();
Init_GL_INTEL_framebuffer_CMAA();
Init_GL_MESA_resize_buffers();
Init_GL_MESA_window_pos();
Init_GL_NVX_conditional_render();
Init_GL_NV_bindless_multi_draw_indirect();
Init_GL_NV_bindless_multi_draw_indirect_count();
Init_GL_NV_bindless_texture();
Init_GL_NV_copy_image();
Init_GL_NV_draw_texture();
Init_GL_NV_texture_barrier();
Init_GL_NV_vertex_attrib_integer_64bit();
Init_GL_OES_byte_coordinates();
Init_GL_OES_query_matrix();
Init_GL_OES_single_precision();
Init_GL_SGIX_flush_raster();
Init_GL_SGIX_igloo_interface();
Init_GL_SGIX_tag_sample_buffer();
Init_GL_SUN_vertex();

#ifdef LOAD_LIBRARY
//printf( "Closing libhandler %08X\n", (unsigned int) m_libhandler );
dlclose( m_libhandler );
#endif // LOAD_LIBRARY
}

// --------------------------------------------------------------------------
// Initialise extension GL_3DFX_tbuffer
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_3DFX_tbuffer( void )
{
#ifdef GL_3DFX_tbuffer
if (!m_GL_3DFX_tbuffer)
	return;

glTbufferMask3DFX = (PFNGLTBUFFERMASK3DFXPROC) GetGLProcAddress( "glTbufferMask3DFX");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_AMD_draw_buffers_blend
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_AMD_draw_buffers_blend( void )
{
#ifdef GL_AMD_draw_buffers_blend
if (!m_GL_AMD_draw_buffers_blend)
	return;

glBlendFuncIndexedAMD = (PFNGLBLENDFUNCINDEXEDAMDPROC) GetGLProcAddress( "glBlendFuncIndexedAMD");
glBlendFuncSeparateIndexedAMD = (PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC) GetGLProcAddress( "glBlendFuncSeparateIndexedAMD");
glBlendEquationIndexedAMD = (PFNGLBLENDEQUATIONINDEXEDAMDPROC) GetGLProcAddress( "glBlendEquationIndexedAMD");
glBlendEquationSeparateIndexedAMD = (PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC) GetGLProcAddress( "glBlendEquationSeparateIndexedAMD");
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

void CExtensionManager::Init_GL_AMD_multi_draw_indirect( void )
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

void CExtensionManager::Init_GL_ARB_draw_buffers_blend( void )
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

void CExtensionManager::Init_GL_ARB_draw_instanced( void )
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

void CExtensionManager::Init_GL_ARB_window_pos( void )
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
// Initialise extension GL_ATI_map_object_buffer
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_ATI_map_object_buffer( void )
{
#ifdef GL_ATI_map_object_buffer
if (!m_GL_ATI_map_object_buffer)
	return;

glMapObjectBufferATI = (PFNGLMAPOBJECTBUFFERATIPROC) GetGLProcAddress( "glMapObjectBufferATI");
glUnmapObjectBufferATI = (PFNGLUNMAPOBJECTBUFFERATIPROC) GetGLProcAddress( "glUnmapObjectBufferATI");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_ATI_vertex_attrib_array_object
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_ATI_vertex_attrib_array_object( void )
{
#ifdef GL_ATI_vertex_attrib_array_object
if (!m_GL_ATI_vertex_attrib_array_object)
	return;

glVertexAttribArrayObjectATI = (PFNGLVERTEXATTRIBARRAYOBJECTATIPROC) GetGLProcAddress( "glVertexAttribArrayObjectATI");
glGetVertexAttribArrayObjectfvATI = (PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC) GetGLProcAddress( "glGetVertexAttribArrayObjectfvATI");
glGetVertexAttribArrayObjectivATI = (PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC) GetGLProcAddress( "glGetVertexAttribArrayObjectivATI");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_EXT_color_subtable
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_EXT_color_subtable( void )
{
#ifdef GL_EXT_color_subtable
if (!m_GL_EXT_color_subtable)
	return;

glColorSubTableEXT = (PFNGLCOLORSUBTABLEEXTPROC) GetGLProcAddress( "glColorSubTableEXT");
glCopyColorSubTableEXT = (PFNGLCOPYCOLORSUBTABLEEXTPROC) GetGLProcAddress( "glCopyColorSubTableEXT");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_EXT_copy_texture
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_EXT_copy_texture( void )
{
#ifdef GL_EXT_copy_texture
if (!m_GL_EXT_copy_texture)
	return;

glCopyTexImage1DEXT = (PFNGLCOPYTEXIMAGE1DEXTPROC) GetGLProcAddress( "glCopyTexImage1DEXT");
glCopyTexImage2DEXT = (PFNGLCOPYTEXIMAGE2DEXTPROC) GetGLProcAddress( "glCopyTexImage2DEXT");
glCopyTexSubImage1DEXT = (PFNGLCOPYTEXSUBIMAGE1DEXTPROC) GetGLProcAddress( "glCopyTexSubImage1DEXT");
glCopyTexSubImage2DEXT = (PFNGLCOPYTEXSUBIMAGE2DEXTPROC) GetGLProcAddress( "glCopyTexSubImage2DEXT");
glCopyTexSubImage3DEXT = (PFNGLCOPYTEXSUBIMAGE3DEXTPROC) GetGLProcAddress( "glCopyTexSubImage3DEXT");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_EXT_debug_marker
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_EXT_debug_marker( void )
{
#ifdef GL_EXT_debug_marker
if (!m_GL_EXT_debug_marker)
	return;

glInsertEventMarkerEXT = (PFNGLINSERTEVENTMARKEREXTPROC) GetGLProcAddress( "glInsertEventMarkerEXT");
glPushGroupMarkerEXT = (PFNGLPUSHGROUPMARKEREXTPROC) GetGLProcAddress( "glPushGroupMarkerEXT");
glPopGroupMarkerEXT = (PFNGLPOPGROUPMARKEREXTPROC) GetGLProcAddress( "glPopGroupMarkerEXT");
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

void CExtensionManager::Init_GL_EXT_draw_buffers2( void )
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

void CExtensionManager::Init_GL_EXT_draw_instanced( void )
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

void CExtensionManager::Init_GL_EXT_gpu_program_parameters( void )
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

void CExtensionManager::Init_GL_EXT_multi_draw_arrays( void )
{
#ifdef GL_EXT_multi_draw_arrays
if (!m_GL_EXT_multi_draw_arrays)
	return;

glMultiDrawArraysEXT = (PFNGLMULTIDRAWARRAYSEXTPROC) GetGLProcAddress( "glMultiDrawArraysEXT");
glMultiDrawElementsEXT = (PFNGLMULTIDRAWELEMENTSEXTPROC) GetGLProcAddress( "glMultiDrawElementsEXT");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_EXT_subtexture
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_EXT_subtexture( void )
{
#ifdef GL_EXT_subtexture
if (!m_GL_EXT_subtexture)
	return;

glTexSubImage1DEXT = (PFNGLTEXSUBIMAGE1DEXTPROC) GetGLProcAddress( "glTexSubImage1DEXT");
glTexSubImage2DEXT = (PFNGLTEXSUBIMAGE2DEXTPROC) GetGLProcAddress( "glTexSubImage2DEXT");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_GREMEDY_frame_terminator
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_GREMEDY_frame_terminator( void )
{
#ifdef GL_GREMEDY_frame_terminator
if (!m_GL_GREMEDY_frame_terminator)
	return;

glFrameTerminatorGREMEDY = (PFNGLFRAMETERMINATORGREMEDYPROC) GetGLProcAddress( "glFrameTerminatorGREMEDY");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_GREMEDY_string_marker
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_GREMEDY_string_marker( void )
{
#ifdef GL_GREMEDY_string_marker
if (!m_GL_GREMEDY_string_marker)
	return;

glStringMarkerGREMEDY = (PFNGLSTRINGMARKERGREMEDYPROC) GetGLProcAddress( "glStringMarkerGREMEDY");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_IBM_multimode_draw_arrays
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_IBM_multimode_draw_arrays( void )
{
#ifdef GL_IBM_multimode_draw_arrays
if (!m_GL_IBM_multimode_draw_arrays)
	return;

glMultiModeDrawArraysIBM = (PFNGLMULTIMODEDRAWARRAYSIBMPROC) GetGLProcAddress( "glMultiModeDrawArraysIBM");
glMultiModeDrawElementsIBM = (PFNGLMULTIMODEDRAWELEMENTSIBMPROC) GetGLProcAddress( "glMultiModeDrawElementsIBM");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_INGR_blend_func_separate
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_INGR_blend_func_separate( void )
{
#ifdef GL_INGR_blend_func_separate
if (!m_GL_INGR_blend_func_separate)
	return;

glBlendFuncSeparateINGR = (PFNGLBLENDFUNCSEPARATEINGRPROC) GetGLProcAddress( "glBlendFuncSeparateINGR");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_INTEL_framebuffer_CMAA
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_INTEL_framebuffer_CMAA( void )
{
#ifdef GL_INTEL_framebuffer_CMAA
if (!m_GL_INTEL_framebuffer_CMAA)
	return;

glApplyFramebufferAttachmentCMAAINTEL = (PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC) GetGLProcAddress( "glApplyFramebufferAttachmentCMAAINTEL");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_MESA_resize_buffers
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_MESA_resize_buffers( void )
{
#ifdef GL_MESA_resize_buffers
if (!m_GL_MESA_resize_buffers)
	return;

glResizeBuffersMESA = (PFNGLRESIZEBUFFERSMESAPROC) GetGLProcAddress( "glResizeBuffersMESA");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_MESA_window_pos
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_MESA_window_pos( void )
{
#ifdef GL_MESA_window_pos
if (!m_GL_MESA_window_pos)
	return;

glWindowPos2dMESA = (PFNGLWINDOWPOS2DMESAPROC) GetGLProcAddress( "glWindowPos2dMESA");
glWindowPos2dvMESA = (PFNGLWINDOWPOS2DVMESAPROC) GetGLProcAddress( "glWindowPos2dvMESA");
glWindowPos2fMESA = (PFNGLWINDOWPOS2FMESAPROC) GetGLProcAddress( "glWindowPos2fMESA");
glWindowPos2fvMESA = (PFNGLWINDOWPOS2FVMESAPROC) GetGLProcAddress( "glWindowPos2fvMESA");
glWindowPos2iMESA = (PFNGLWINDOWPOS2IMESAPROC) GetGLProcAddress( "glWindowPos2iMESA");
glWindowPos2ivMESA = (PFNGLWINDOWPOS2IVMESAPROC) GetGLProcAddress( "glWindowPos2ivMESA");
glWindowPos2sMESA = (PFNGLWINDOWPOS2SMESAPROC) GetGLProcAddress( "glWindowPos2sMESA");
glWindowPos2svMESA = (PFNGLWINDOWPOS2SVMESAPROC) GetGLProcAddress( "glWindowPos2svMESA");
glWindowPos3dMESA = (PFNGLWINDOWPOS3DMESAPROC) GetGLProcAddress( "glWindowPos3dMESA");
glWindowPos3dvMESA = (PFNGLWINDOWPOS3DVMESAPROC) GetGLProcAddress( "glWindowPos3dvMESA");
glWindowPos3fMESA = (PFNGLWINDOWPOS3FMESAPROC) GetGLProcAddress( "glWindowPos3fMESA");
glWindowPos3fvMESA = (PFNGLWINDOWPOS3FVMESAPROC) GetGLProcAddress( "glWindowPos3fvMESA");
glWindowPos3iMESA = (PFNGLWINDOWPOS3IMESAPROC) GetGLProcAddress( "glWindowPos3iMESA");
glWindowPos3ivMESA = (PFNGLWINDOWPOS3IVMESAPROC) GetGLProcAddress( "glWindowPos3ivMESA");
glWindowPos3sMESA = (PFNGLWINDOWPOS3SMESAPROC) GetGLProcAddress( "glWindowPos3sMESA");
glWindowPos3svMESA = (PFNGLWINDOWPOS3SVMESAPROC) GetGLProcAddress( "glWindowPos3svMESA");
glWindowPos4dMESA = (PFNGLWINDOWPOS4DMESAPROC) GetGLProcAddress( "glWindowPos4dMESA");
glWindowPos4dvMESA = (PFNGLWINDOWPOS4DVMESAPROC) GetGLProcAddress( "glWindowPos4dvMESA");
glWindowPos4fMESA = (PFNGLWINDOWPOS4FMESAPROC) GetGLProcAddress( "glWindowPos4fMESA");
glWindowPos4fvMESA = (PFNGLWINDOWPOS4FVMESAPROC) GetGLProcAddress( "glWindowPos4fvMESA");
glWindowPos4iMESA = (PFNGLWINDOWPOS4IMESAPROC) GetGLProcAddress( "glWindowPos4iMESA");
glWindowPos4ivMESA = (PFNGLWINDOWPOS4IVMESAPROC) GetGLProcAddress( "glWindowPos4ivMESA");
glWindowPos4sMESA = (PFNGLWINDOWPOS4SMESAPROC) GetGLProcAddress( "glWindowPos4sMESA");
glWindowPos4svMESA = (PFNGLWINDOWPOS4SVMESAPROC) GetGLProcAddress( "glWindowPos4svMESA");
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

void CExtensionManager::Init_GL_NVX_conditional_render( void )
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

void CExtensionManager::Init_GL_NV_bindless_multi_draw_indirect( void )
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

void CExtensionManager::Init_GL_NV_bindless_multi_draw_indirect_count( void )
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

void CExtensionManager::Init_GL_NV_bindless_texture( void )
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

void CExtensionManager::Init_GL_NV_copy_image( void )
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

void CExtensionManager::Init_GL_NV_draw_texture( void )
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

void CExtensionManager::Init_GL_NV_texture_barrier( void )
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

void CExtensionManager::Init_GL_NV_vertex_attrib_integer_64bit( void )
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

// --------------------------------------------------------------------------
// Initialise extension GL_OES_byte_coordinates
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_OES_byte_coordinates( void )
{
#ifdef GL_OES_byte_coordinates
if (!m_GL_OES_byte_coordinates)
	return;

glMultiTexCoord1bOES = (PFNGLMULTITEXCOORD1BOESPROC) GetGLProcAddress( "glMultiTexCoord1bOES");
glMultiTexCoord1bvOES = (PFNGLMULTITEXCOORD1BVOESPROC) GetGLProcAddress( "glMultiTexCoord1bvOES");
glMultiTexCoord2bOES = (PFNGLMULTITEXCOORD2BOESPROC) GetGLProcAddress( "glMultiTexCoord2bOES");
glMultiTexCoord2bvOES = (PFNGLMULTITEXCOORD2BVOESPROC) GetGLProcAddress( "glMultiTexCoord2bvOES");
glMultiTexCoord3bOES = (PFNGLMULTITEXCOORD3BOESPROC) GetGLProcAddress( "glMultiTexCoord3bOES");
glMultiTexCoord3bvOES = (PFNGLMULTITEXCOORD3BVOESPROC) GetGLProcAddress( "glMultiTexCoord3bvOES");
glMultiTexCoord4bOES = (PFNGLMULTITEXCOORD4BOESPROC) GetGLProcAddress( "glMultiTexCoord4bOES");
glMultiTexCoord4bvOES = (PFNGLMULTITEXCOORD4BVOESPROC) GetGLProcAddress( "glMultiTexCoord4bvOES");
glTexCoord1bOES = (PFNGLTEXCOORD1BOESPROC) GetGLProcAddress( "glTexCoord1bOES");
glTexCoord1bvOES = (PFNGLTEXCOORD1BVOESPROC) GetGLProcAddress( "glTexCoord1bvOES");
glTexCoord2bOES = (PFNGLTEXCOORD2BOESPROC) GetGLProcAddress( "glTexCoord2bOES");
glTexCoord2bvOES = (PFNGLTEXCOORD2BVOESPROC) GetGLProcAddress( "glTexCoord2bvOES");
glTexCoord3bOES = (PFNGLTEXCOORD3BOESPROC) GetGLProcAddress( "glTexCoord3bOES");
glTexCoord3bvOES = (PFNGLTEXCOORD3BVOESPROC) GetGLProcAddress( "glTexCoord3bvOES");
glTexCoord4bOES = (PFNGLTEXCOORD4BOESPROC) GetGLProcAddress( "glTexCoord4bOES");
glTexCoord4bvOES = (PFNGLTEXCOORD4BVOESPROC) GetGLProcAddress( "glTexCoord4bvOES");
glVertex2bOES = (PFNGLVERTEX2BOESPROC) GetGLProcAddress( "glVertex2bOES");
glVertex2bvOES = (PFNGLVERTEX2BVOESPROC) GetGLProcAddress( "glVertex2bvOES");
glVertex3bOES = (PFNGLVERTEX3BOESPROC) GetGLProcAddress( "glVertex3bOES");
glVertex3bvOES = (PFNGLVERTEX3BVOESPROC) GetGLProcAddress( "glVertex3bvOES");
glVertex4bOES = (PFNGLVERTEX4BOESPROC) GetGLProcAddress( "glVertex4bOES");
glVertex4bvOES = (PFNGLVERTEX4BVOESPROC) GetGLProcAddress( "glVertex4bvOES");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_OES_query_matrix
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_OES_query_matrix( void )
{
#ifdef GL_OES_query_matrix
if (!m_GL_OES_query_matrix)
	return;

glQueryMatrixxOES = (PFNGLQUERYMATRIXXOESPROC) GetGLProcAddress( "glQueryMatrixxOES");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_OES_single_precision
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_OES_single_precision( void )
{
#ifdef GL_OES_single_precision
if (!m_GL_OES_single_precision)
	return;

glClearDepthfOES = (PFNGLCLEARDEPTHFOESPROC) GetGLProcAddress( "glClearDepthfOES");
glClipPlanefOES = (PFNGLCLIPPLANEFOESPROC) GetGLProcAddress( "glClipPlanefOES");
glDepthRangefOES = (PFNGLDEPTHRANGEFOESPROC) GetGLProcAddress( "glDepthRangefOES");
glFrustumfOES = (PFNGLFRUSTUMFOESPROC) GetGLProcAddress( "glFrustumfOES");
glGetClipPlanefOES = (PFNGLGETCLIPPLANEFOESPROC) GetGLProcAddress( "glGetClipPlanefOES");
glOrthofOES = (PFNGLORTHOFOESPROC) GetGLProcAddress( "glOrthofOES");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_SGIX_flush_raster
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_SGIX_flush_raster( void )
{
#ifdef GL_SGIX_flush_raster
if (!m_GL_SGIX_flush_raster)
	return;

glFlushRasterSGIX = (PFNGLFLUSHRASTERSGIXPROC) GetGLProcAddress( "glFlushRasterSGIX");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_SGIX_igloo_interface
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_SGIX_igloo_interface( void )
{
#ifdef GL_SGIX_igloo_interface
if (!m_GL_SGIX_igloo_interface)
	return;

glIglooInterfaceSGIX = (PFNGLIGLOOINTERFACESGIXPROC) GetGLProcAddress( "glIglooInterfaceSGIX");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_SGIX_tag_sample_buffer
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_SGIX_tag_sample_buffer( void )
{
#ifdef GL_SGIX_tag_sample_buffer
if (!m_GL_SGIX_tag_sample_buffer)
	return;

glTagSampleBufferSGIX = (PFNGLTAGSAMPLEBUFFERSGIXPROC) GetGLProcAddress( "glTagSampleBufferSGIX");
#endif
}

// --------------------------------------------------------------------------
// Initialise extension GL_SUN_vertex
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The extension is initialised
// --------------------------------------------------------------------------

void CExtensionManager::Init_GL_SUN_vertex( void )
{
#ifdef GL_SUN_vertex
if (!m_GL_SUN_vertex)
	return;

glColor4ubVertex2fSUN = (PFNGLCOLOR4UBVERTEX2FSUNPROC) GetGLProcAddress( "glColor4ubVertex2fSUN");
glColor4ubVertex2fvSUN = (PFNGLCOLOR4UBVERTEX2FVSUNPROC) GetGLProcAddress( "glColor4ubVertex2fvSUN");
glColor4ubVertex3fSUN = (PFNGLCOLOR4UBVERTEX3FSUNPROC) GetGLProcAddress( "glColor4ubVertex3fSUN");
glColor4ubVertex3fvSUN = (PFNGLCOLOR4UBVERTEX3FVSUNPROC) GetGLProcAddress( "glColor4ubVertex3fvSUN");
glColor3fVertex3fSUN = (PFNGLCOLOR3FVERTEX3FSUNPROC) GetGLProcAddress( "glColor3fVertex3fSUN");
glColor3fVertex3fvSUN = (PFNGLCOLOR3FVERTEX3FVSUNPROC) GetGLProcAddress( "glColor3fVertex3fvSUN");
glNormal3fVertex3fSUN = (PFNGLNORMAL3FVERTEX3FSUNPROC) GetGLProcAddress( "glNormal3fVertex3fSUN");
glNormal3fVertex3fvSUN = (PFNGLNORMAL3FVERTEX3FVSUNPROC) GetGLProcAddress( "glNormal3fVertex3fvSUN");
glColor4fNormal3fVertex3fSUN = (PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC) GetGLProcAddress( "glColor4fNormal3fVertex3fSUN");
glColor4fNormal3fVertex3fvSUN = (PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC) GetGLProcAddress( "glColor4fNormal3fVertex3fvSUN");
glTexCoord2fVertex3fSUN = (PFNGLTEXCOORD2FVERTEX3FSUNPROC) GetGLProcAddress( "glTexCoord2fVertex3fSUN");
glTexCoord2fVertex3fvSUN = (PFNGLTEXCOORD2FVERTEX3FVSUNPROC) GetGLProcAddress( "glTexCoord2fVertex3fvSUN");
glTexCoord4fVertex4fSUN = (PFNGLTEXCOORD4FVERTEX4FSUNPROC) GetGLProcAddress( "glTexCoord4fVertex4fSUN");
glTexCoord4fVertex4fvSUN = (PFNGLTEXCOORD4FVERTEX4FVSUNPROC) GetGLProcAddress( "glTexCoord4fVertex4fvSUN");
glTexCoord2fColor4ubVertex3fSUN = (PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC) GetGLProcAddress( "glTexCoord2fColor4ubVertex3fSUN");
glTexCoord2fColor4ubVertex3fvSUN = (PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC) GetGLProcAddress( "glTexCoord2fColor4ubVertex3fvSUN");
glTexCoord2fColor3fVertex3fSUN = (PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC) GetGLProcAddress( "glTexCoord2fColor3fVertex3fSUN");
glTexCoord2fColor3fVertex3fvSUN = (PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC) GetGLProcAddress( "glTexCoord2fColor3fVertex3fvSUN");
glTexCoord2fNormal3fVertex3fSUN = (PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC) GetGLProcAddress( "glTexCoord2fNormal3fVertex3fSUN");
glTexCoord2fNormal3fVertex3fvSUN = (PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC) GetGLProcAddress( "glTexCoord2fNormal3fVertex3fvSUN");
glTexCoord2fColor4fNormal3fVertex3fSUN = (PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC) GetGLProcAddress( "glTexCoord2fColor4fNormal3fVertex3fSUN");
glTexCoord2fColor4fNormal3fVertex3fvSUN = (PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC) GetGLProcAddress( "glTexCoord2fColor4fNormal3fVertex3fvSUN");
glTexCoord4fColor4fNormal3fVertex4fSUN = (PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC) GetGLProcAddress( "glTexCoord4fColor4fNormal3fVertex4fSUN");
glTexCoord4fColor4fNormal3fVertex4fvSUN = (PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC) GetGLProcAddress( "glTexCoord4fColor4fNormal3fVertex4fvSUN");
glReplacementCodeuiVertex3fSUN = (PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC) GetGLProcAddress( "glReplacementCodeuiVertex3fSUN");
glReplacementCodeuiVertex3fvSUN = (PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC) GetGLProcAddress( "glReplacementCodeuiVertex3fvSUN");
glReplacementCodeuiColor4ubVertex3fSUN = (PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC) GetGLProcAddress( "glReplacementCodeuiColor4ubVertex3fSUN");
glReplacementCodeuiColor4ubVertex3fvSUN = (PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC) GetGLProcAddress( "glReplacementCodeuiColor4ubVertex3fvSUN");
glReplacementCodeuiColor3fVertex3fSUN = (PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC) GetGLProcAddress( "glReplacementCodeuiColor3fVertex3fSUN");
glReplacementCodeuiColor3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC) GetGLProcAddress( "glReplacementCodeuiColor3fVertex3fvSUN");
glReplacementCodeuiNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC) GetGLProcAddress( "glReplacementCodeuiNormal3fVertex3fSUN");
glReplacementCodeuiNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC) GetGLProcAddress( "glReplacementCodeuiNormal3fVertex3fvSUN");
glReplacementCodeuiColor4fNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC) GetGLProcAddress( "glReplacementCodeuiColor4fNormal3fVertex3fSUN");
glReplacementCodeuiColor4fNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC) GetGLProcAddress( "glReplacementCodeuiColor4fNormal3fVertex3fvSUN");
glReplacementCodeuiTexCoord2fVertex3fSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC) GetGLProcAddress( "glReplacementCodeuiTexCoord2fVertex3fSUN");
glReplacementCodeuiTexCoord2fVertex3fvSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC) GetGLProcAddress( "glReplacementCodeuiTexCoord2fVertex3fvSUN");
glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC) GetGLProcAddress( "glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN");
glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC) GetGLProcAddress( "glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN");
glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC) GetGLProcAddress( "glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN");
glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC) GetGLProcAddress( "glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN");
#endif
}

