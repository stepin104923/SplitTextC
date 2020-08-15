/**
* @file split_text_internal.h
* @brief This is not part of the program API. It might be removed / hidden
*        without any indication. Please do not use it directly.
*/
#ifndef __SPLIT_TEXT_INTERNAL_H__
#define __SPLIT_TEXT_INTERNAL_H__

/**
* Finds the number of pieces a text will be split into by the delimiter `_`
* @param[in] text String to be split
* @return Number of pieces
* @note This subroutine does not mutate the input string
*/
int get_pieces_count(char *text);

#endif /* #ifndef __SPLIT_TEXT_INTERNAL_H__ */