/**
* @file split_text.h
*
*/
#ifndef __SPLIT_TEXT_H__
#define __SPLIT_TEXT_H__

/**
* Breaks a text into pieces depending on a delimiter `_`
* @param[in] text String to be split
* @return List of strings terminated by `NULL`
* @note This subroutine does not mutate the input string
* @warning Free the memory allocated for the pieces using #free_pieces after
           using them
*/
char** split_text(char *text);

/**
 * Releases the memory held by the pieces structure
 * @param[in] pieces The output of #split_text
*/
void free_pieces(char** pieces);

#endif /* #ifndef __SPLIT_TEXT_H__ */
