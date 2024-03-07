-- The average energy of songs that are by Drake
SELECT AVG(energy) AS energy FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name="Drake");
