/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slib.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:35:03 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/21 12:35:04 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLIB_H
# define SLIB_H

# include "common.h"

bool					is_alnum(int32_t ch);
bool					is_alpha(int32_t ch);
bool					is_ascii(int32_t ch);
bool					is_binary(int32_t ch);
bool					is_decimal(int32_t ch);
bool					is_digit(int32_t ch);
bool					is_even(int32_t ch);
bool					is_hex(int32_t ch);
bool					is_lowercase(int32_t ch);
bool					is_newline(int32_t ch);
bool					is_octal(int32_t ch);
bool					is_odd(int32_t ch);
bool					is_printable(int32_t ch);
bool					is_spaces(int32_t ch);
bool					is_uppercase(int32_t ch);
bool					is_whitespace(int32_t ch);
int32_t					to_lowercase(int32_t ch);
int32_t					to_reversecase(int32_t ch);
int32_t					to_uppercase(int32_t ch);

void					*alloc(uint64_t byte_size);
void					*dealloc(void *ptr);
void					*resize(void *ptr, uint64_t old_size,
							uint64_t new_size);
void					*dupe(void *ptr, uint64_t byte_size);
void					*dupz(void *ptr, uint64_t byte_size);
void					*zeroed(void *ptr, uint64_t byte_size);
void					*filled(void *ptr, uint8_t byte, uint64_t byte_size);
void					*memcopy(void *dest, void *source, uint64_t byte_size);

# define BITSET_SIZE 256

typedef struct s_bitset
{
	union
	{
		uint64_t		set[4];
		struct
		{
			uint64_t	a;
			uint64_t	b;
			uint64_t	c;
			uint64_t	d;
		};
	};
}						t_bitset;

void					bitset_set_bit(t_bitset *bitset, uint64_t index,
							bool value);
bool					bitset_is_set(t_bitset *bitset, uint64_t index);
t_bitset				bitset_set_bit_range(t_bitset *bitset, char *string);
t_bitset				bitset_init_empty(void);
t_bitset				bitset_init_from_str(char *string);
t_bitset				bitset_and(t_bitset *bitset1, t_bitset *bitset2);
t_bitset				bitset_or(t_bitset *bitset1, t_bitset *bitset2);
t_bitset				bitset_xor(t_bitset *bitset1, t_bitset *bitset2);
t_bitset				bitset_difference(t_bitset *bitset1, t_bitset *bitset2);

uint64_t				string_length(char *string);
uint64_t				string_split_length(char **split);
uint64_t				string_split_size(char **split);

uint64_t				string_index_of_difference(char *s1, char *s2);
uint64_t				string_compute_replace_sequence_size(char *haystack,
							char *needle, char *with);

uint64_t				string_compute_scalar_split_size(char *source,
							int32_t scalar);
uint64_t				string_compute_any_split_size(char *source,
							t_bitset *delimiters);
uint64_t				string_compute_none_split_size(char *source,
							t_bitset *delimiters);
uint64_t				string_compute_predicate_split_size(char *source,
							bool(predicate)(int32_t ch));
uint64_t				string_compute_sequence_split_size(char *source,
							char *needle);

int32_t					string_compare(char *s1, char *s2);
int32_t					string_ncompare(char *s1, char *s2, uint64_t n);
int32_t					string_casecompare(char *s1, char *s2);
int32_t					string_ncasecompare(char *s1, char *s2, uint64_t n);

uint64_t				string_copy_until_scalar(char *dest, char *src,
							int32_t scalar, uint64_t destsize);
uint64_t				string_copy_until_any(char *dest, char *src,
							t_bitset *delimiters, uint64_t destsize);
uint64_t				string_copy_until_none(char *dest, char *src,
							t_bitset *delimiters, uint64_t destsize);
uint64_t				string_copy_until_predicate(char *dest, char *src,
							bool(predicate)(int32_t ch), uint64_t destsize);
uint64_t				string_copy_until_sequence(char *dest, char *src,
							char *needle, uint64_t destsize);

bool					string_is_all_scalar(char *source, int32_t scalar);
bool					string_is_all_any(char *source, t_bitset *any);
bool					string_is_all_none(char *source, t_bitset *none);
bool					string_is_all_predicate(char *source,
							bool(predicate)(int32_t ch));
bool					string_is_all_sequence(char *source, char *sequence);

char					*string_tokenize_scalar(char *source, int32_t scalar,
							int32_t marker);
char					*string_tokenize_any(char *source, t_bitset *delimiters,
							int32_t marker);
char					*string_tokenize_none(char *source,
							t_bitset *delimiters, int32_t marker);
char					*string_tokenize_predicate(char *source,
							bool(predicate)(int32_t ch), int32_t marker);
char					*string_tokenize_sequence(char *haystack, char *needle,
							int32_t marker);

char					*string_search_scalar(char *source, int32_t scalar,
							uint64_t n);
char					*string_search_any(char *source, t_bitset *delimiters,
							uint64_t n);
char					*string_search_none(char *source, t_bitset *delimiters,
							uint64_t n);
char					*string_search_predicate(char *source,
							bool(predicate)(int32_t ch), uint64_t n);
char					*string_search_sequence(char *haystack, char *needle,
							uint64_t n);

bool					string_contains_scalar(char *source, int32_t scalar,
							uint64_t n);
bool					string_contains_any(char *source, t_bitset *delimiters,
							uint64_t n);
bool					string_contains_none(char *source, t_bitset *delimiters,
							uint64_t n);
bool					string_contains_predicate(char *source,
							bool(predicate)(int32_t ch), uint64_t n);
bool					string_contains_sequence(char *needle, char *haystack,
							uint64_t n);

bool					string_starts_with_scalar(char *source, int32_t scalar);
bool					string_starts_with_any(char *source,
							t_bitset *delimiters);
bool					string_starts_with_none(char *source,
							t_bitset *delimiters);
bool					string_starts_with_predicate(char *source,
							bool(predicate)(int32_t ch));
bool					string_starts_with_sequence(char *haystack,
							char *needle);

bool					string_ends_with_scalar(char *source, int32_t scalar);
bool					string_ends_with_any(char *source,
							t_bitset *delimiters);
bool					string_ends_with_none(char *source,
							t_bitset *delimiters);
bool					string_ends_with_predicate(char *source,
							bool(predicate)(int32_t ch));
bool					string_ends_with_sequence(char *haystack, char *needle);

uint64_t				string_index_of_first_scalar(char *source,
							int32_t scalar);
uint64_t				string_index_of_first_any(char *source,
							t_bitset *delimiters);
uint64_t				string_index_of_first_none(char *source,
							t_bitset *delimiters);
uint64_t				string_index_of_first_predicate(char *source,
							bool(predicate)(int32_t ch));
uint64_t				string_index_of_first_sequence(char *haystack,
							char *needle);

uint64_t				string_index_of_last_scalar(char *source,
							int32_t scalar);
uint64_t				string_index_of_last_any(char *source,
							t_bitset *delimiters);
uint64_t				string_index_of_last_none(char *source,
							t_bitset *delimiters);
uint64_t				string_index_of_last_predicate(char *source,
							bool(predicate)(int32_t ch));
uint64_t				string_index_of_last_sequence(char *haystack,
							char *needle);

uint64_t				string_count_scalar(char *source, int32_t scalar,
							uint64_t n);
uint64_t				string_count_any(char *source, t_bitset *delimiters,
							uint64_t n);
uint64_t				string_count_none(char *source, t_bitset *delimiters,
							uint64_t n);
uint64_t				string_count_predicate(char *source,
							bool(predicate)(int32_t ch), uint64_t n);
uint64_t				string_count_sequence(char *haystack, char *needle,
							uint64_t n);

uint64_t				string_count_until_scalar(char *source, int32_t scalar);
uint64_t				string_count_until_any(char *source,
							t_bitset *delimiters);
uint64_t				string_count_until_none(char *source,
							t_bitset *delimiters);
uint64_t				string_count_until_predicate(char *source,
							bool(predicate)(int32_t ch));
uint64_t				string_count_until_sequence(char *haystack,
							char *needle);

uint64_t				string_count_leading_scalar(char *source,
							int32_t scalar);
uint64_t				string_count_leading_any(char *source,
							t_bitset *delimiters);
uint64_t				string_count_leading_none(char *source,
							t_bitset *delimiters);
uint64_t				string_count_leading_predicate(char *source,
							bool(predicate)(int32_t ch));
uint64_t				string_count_leading_sequence(char *haystack,
							char *needle);

uint64_t				string_count_trailing_scalar(char *source,
							int32_t scalar);
uint64_t				string_count_trailing_any(char *source,
							t_bitset *delimiters);
uint64_t				string_count_trailing_none(char *source,
							t_bitset *delimiters);
uint64_t				string_count_trailing_predicate(char *source,
							bool(predicate)(int32_t ch));
uint64_t				string_count_trailing_sequence(char *haystack,
							char *needle);

uint64_t				string_wcount_scalar(char *source, int32_t scalar);
uint64_t				string_wcount_any(char *source, t_bitset *delimiters);
uint64_t				string_wcount_none(char *source, t_bitset *delimiters);
uint64_t				string_wcount_predicate(char *source,
							bool(predicate)(int32_t ch));
uint64_t				string_wcount_sequence(char *source, char *sequence);

uint64_t				string_wlength_scalar(char *source, int32_t scalar);
uint64_t				string_wlength_any(char *source, t_bitset *delimiters);
uint64_t				string_wlength_none(char *source, t_bitset *delimiters);
uint64_t				string_wlength_predicate(char *source,
							bool(predicate)(int32_t ch));
uint64_t				string_wlength_sequence(char *source, char *sequence);

uint64_t				string_wfind_scalar(char *source, int32_t scalar,
							uint64_t *out_start, uint64_t *out_end);
uint64_t				string_wfind_any(char *source, t_bitset *delimiters,
							uint64_t *out_start, uint64_t *out_end);
uint64_t				string_wfind_none(char *source, t_bitset *delimiters,
							uint64_t *out_start, uint64_t *out_end);
uint64_t				string_wfind_predicate(char *source,
							bool(predicate)(int32_t ch), uint64_t *out_start,
							uint64_t *out_end);
uint64_t				string_wfind_sequence(char *source, char *needle,
							uint64_t *out_start, uint64_t *out_end);

char					*string_clone(char *src);
char					*string_clone_scalar(int32_t ch);
char					*string_nclone(char *src, uint64_t n);

char					*string_clone_until_scalar(char *src, int32_t scalar);
char					*string_clone_until_any(char *src,
							t_bitset *delimiters);
char					*string_clone_until_none(char *src,
							t_bitset *delimiters);
char					*string_clone_until_predicate(char *src,
							bool(predicate)(int32_t ch));
char					*string_clone_until_sequence(char *src, char *needle);

char					*string_substring_scalar(char *src, int32_t scalar);
char					*string_substring_any(char *src, t_bitset *delimiters);
char					*string_substring_none(char *src, t_bitset *delimiters);
char					*string_substring_predicate(char *src,
							bool(predicate)(int32_t ch));
char					*string_substring_sequence(char *src, char *needle);

char					*string_join_scalar(char *string, int32_t scalar);
char					*string_join_sequence(char *string, char *sequence);
char					*string_join_scalar_sequence(char *string,
							int32_t scalar, char *sequence);
char					*string_join_many_sequence(char *string, char **many);
char					*string_join_many_scalar_sequence(char *string,
							int32_t scalar, char **many);

char					*string_pad_left_scalar(char *string, int32_t scalar,
							uint64_t amount);
char					*string_pad_right_scalar(char *string, int32_t scalar,
							uint64_t amount);
char					*string_pad_left_sequence(char *string, char *sequence,
							uint64_t amount);
char					*string_pad_right_sequence(char *string, char *sequence,
							uint64_t amount);

char					*string_append_scalar(char *dest, int32_t scalar,
							uint64_t destsize);
char					*string_append_sequence(char *dest, char *sequence,
							uint64_t destsize);
char					*string_append_scalar_sequence(char *dest,
							int32_t scalar, char *sequence, uint64_t destsize);
char					*string_append_many_sequence(char *dest, char **many,
							uint64_t destsize);
char					*string_append_many_scalar_sequence(char *dest,
							int32_t scalar, char **many, uint64_t destsize);

char					*string_trim_left(char *source, uint64_t amount);
char					*string_trim_right(char *source, uint64_t amount);
char					*string_trim_both(char *source, uint64_t amount);

char					*string_trim_leading_scalar(char *source,
							int32_t scalar);
char					*string_trim_leading_any(char *source,
							t_bitset *delimiters);
char					*string_trim_leading_none(char *source,
							t_bitset *delimiters);
char					*string_trim_leading_predicate(char *source,
							bool(predicate)(int32_t ch));
char					*string_trim_leading_sequence(char *haystack,
							char *needle);

char					*string_trim_trailing_scalar(char *source,
							int32_t scalar);
char					*string_trim_trailing_any(char *source,
							t_bitset *delimiters);
char					*string_trim_trailing_none(char *source,
							t_bitset *delimiters);
char					*string_trim_trailing_predicate(char *source,
							bool(predicate)(int32_t ch));
char					*string_trim_trailing_sequence(char *haystack,
							char *needle);

char					*string_filter_scalar(char *source, int32_t scalar);
char					*string_filter_any(char *source, t_bitset *delimiters);
char					*string_filter_none(char *source, t_bitset *delimiters);
char					*string_filter_predicate(char *source,
							bool(predicate)(int32_t ch));
char					*string_filter_sequence(char *haystack, char *needle);

char					*string_replace_scalar(char *source, int32_t scalar,
							int32_t with);
char					*string_replace_any(char *source, t_bitset *delimiters,
							int32_t with);
char					*string_replace_none(char *source, t_bitset *delimiters,
							int32_t with);
char					*string_replace_predicate(char *source,
							bool(predicate)(int32_t ch), int32_t with);
char					*string_replace_sequence(char *haystack, char *needle,
							char *with, char *out_buffer);

char					**string_split_scalar(char *source, int32_t scalar);
char					**string_split_any(char *source, t_bitset *delimiters);
char					**string_split_none(char *source, t_bitset *delimiters);
char					**string_split_predicate(char *source,
							bool(predicate)(int32_t ch));
char					**string_split_sequence(char *haystack, char *needle);

char					*string_to_reverse(char *source);
char					*string_to_uppercase(char *source);
char					*string_to_lowercase(char *source);
char					*string_to_titlecase(char *source);
char					*string_to_capitalcase(char *source);

t_node					*node_create(uintptr_t data);
t_node					*node_destroy(t_node *self);
t_node					*node_get_nchild(t_node *self, uint64_t n);
void					node_insert_child(t_node *self, t_node *child);
t_node					*node_remove_child(t_node *self);
uint64_t				node_count_child(t_node *self);
t_list					*list_create(void);
t_list					*list_destroy(t_list *self);
void					list_insert_front(t_list *self, t_node *new_head);
void					list_copy(t_list *dest, t_list *src,
							uintptr_t (*ctor)(uintptr_t data));
void					list_concat(t_list *dest, t_list *src);
void					list_insert_at(t_list *self, t_node *node,
							uint64_t index);
void					list_insert_back(t_list *self, t_node *new_tail);
void					list_push_front(t_list *self, uintptr_t data);
void					list_push_at(t_list *self, uintptr_t data,
							uint64_t index);
void					list_push_back(t_list *self, uintptr_t data);
void					list_sort(t_node **list,
							int64_t (*compare)(uintptr_t d1, uintptr_t d2));
t_node					*list_remove_front(t_list *self);
t_node					*list_remove_back(t_list *self);
t_node					*list_remove_at(t_list *self, uint64_t index);
uintptr_t				list_pop_front(t_list *self);
uintptr_t				list_pop_back(t_list *self);
uintptr_t				list_pop_at(t_list *self, uint64_t index);
uintptr_t				list_peek_front(t_list *self);
uintptr_t				list_peek_back(t_list *self);
uintptr_t				list_peek_at(t_list *self, uint64_t index);
uint64_t				list_size(t_list *self);
bool					list_is_empty(t_list *self);
void					list_map(t_list *self, void (fn)(uintptr_t data));
void					list_clear_retain_capacity(t_list *self,
							uintptr_t (*dtor)(uintptr_t data));
void					list_clear(t_list *self,
							uintptr_t (*dtor)(uintptr_t data));
void					list_dump(t_list *dest, t_list *src);
int64_t					list_index_of(t_list *self, uintptr_t data,
							int64_t (*compare)(uintptr_t d1, uintptr_t d2));
char					**list_to_split(t_list *self);

t_hashmap				*hashmap_create(uint64_t capacity);
void					hashmap_destroy(t_hashmap *self);
void					hashmap_put(t_hashmap *self, char *key,
							uintptr_t value);
uintptr_t				hashmap_get(t_hashmap *self, char *key);
uint64_t				hashmap_hash(char *str);
t_entry					*hashmap_body_create(uint64_t capacity);
void					hashmap_body_remove(t_hashmap *self, char *key);
void					hashmap_body_resize(t_hashmap *self, uint64_t capacity);
uint64_t				hashmap_body_find_empty(t_hashmap *self, char *key);
bool					is_prime(uint64_t num);
uint64_t				find_next_prime(uint64_t num);

#endif
