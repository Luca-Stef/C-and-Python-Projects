select name from people join (directors join (movies join ratings on movies.id = ratings.movie_id) on directors.movie_id = movies.id) on people.id = directors.person_id where rating >= 9;