SELECT
    concat('/home/grep/src/',f.board_id,'/',f.file_id,f.file_name,f.file_ext) AS file_path
FROM USED_GOODS_FILE f
JOIN USED_GOODS_BOARD b ON b.board_id = f.board_id
where views=(select max(views) from used_goods_board)
ORDER BY f.file_id desc, b.views DESC