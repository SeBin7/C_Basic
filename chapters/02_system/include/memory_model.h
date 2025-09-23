#ifndef MEMORY_MODEL_H
#define MEMORY_MODEL_H

#ifdef __cplusplus
extern "C" {
#endif

	void demo_segments(void);
	void demo_stack_heap(void);
	void demo_struct_padding(void);
	void dump_proc_maps_short(int max_lines);

#ifdef __cplusplus
}
#endif
#endif
