/* Tokens.  */
#define AUTO_tok 258
#define BREAK_tok 259
#define CASE_tok 260
#define CHAR_tok 261
#define CONST_tok 262
#define CONTINUE_tok 263
#define DEFAULT_tok 264
#define DO_tok 265
#define DOUBLE_tok 266
#define ELSE_tok 267
#define ENUM_tok 268
#define EXTERN_tok 269
#define FLOAT_tok 270
#define FOR_tok 271
#define GOTO_tok 272
#define IF_tok 273
#define INT_tok 274
#define LONG_tok 275
#define REGISTER_tok 276
#define RETURN_tok 277
#define SHORT_tok 278
#define SIGNED_tok 279
#define SIZEOF_tok 280
#define STATIC_tok 281
#define STRUCT_tok 282
#define SWITCH_tok 283
#define TYPEDEF_tok 284
#define UNION_tok 285
#define UNSIGNED_tok 286
#define VOID_tok 287
#define VOLATILE_tok 288
#define WHILE_tok 289
#define ERROR_tok 290
#define ID_tok 291
#define PLUS_tok 292
#define MINUS_tok 293
#define STAR_tok 294
#define SEMI_tok 295
#define OPEN_BRACKET_tok 296
#define CLOSE_BRACKET_tok 297
#define EQUAL_tok 298
#define COLON_tok 299
#define COMMA_tok 300
#define OPEN_PAREN_tok 301
#define CLOSE_PAREN_tok 302
#define OPEN_BRACE_tok 303
#define CLOSE_BRACE_tok 304
#define QUESTION_MARK_tok 305
#define BAR_tok 306
#define CARET_tok 307
#define AMP_tok 308
#define GT_tok 309
#define LT_tok 310
#define PERCENT_tok 311
#define TILDA_tok 312
#define NOT_tok 313
#define INC_OP_tok 314
#define DEC_OP_tok 315
#define INTEGER_CONSTANT_tok 316
#define FLOATING_CONSTANT_tok 317

#define CHARACTER_CONSTANT_tok 318
#define ENUMERATION_CONSTANT_tok 319
#define STRING_LITERAL_tok 320

#define PTR_OP_tok 321
#define LEFT_OP_tok 322
#define RIGHT_OP_tok 323
#define LE_OP_tok 324
#define GE_OP_tok 325
#define EQ_OP_tok 326
#define NE_OP_tok 327
#define AND_OP_tok 328
#define OR_OP_tok 329
#define MULT_ASSIGN_tok 330
#define DIV_ASSIGN_tok 331
#define MOD_ASSIGN_tok 332
#define ADD_ASSIGN_tok 333
#define SUB_ASSIGN_tok 334
#define LEFT_ASSIGN_tok 335
#define RIGHT_ASSIGN_tok 336
#define AND_ASSIGN_tok 337
#define XOR_ASSIGN_tok 338
#define OR_ASSIGN_tok 339
#define TYPEDEF_NAME_tok 340
#define ELIPSIS_tok 341
#define DIV_tok 342
#define PERIOD_tok 343


int lex_debug_level;
int symbol_table_debug;
int yacc_debug_level;
int insert_lookup;
int yylval;