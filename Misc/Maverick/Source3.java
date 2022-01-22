import java.util.*;

class Movie {
    private int movieId;
    private String movieName;
    private String genre;

    Movie(int movieId, String movieName, String genre){
        this.movieId = movieId;
        this.movieName = movieName;
        this.genre = genre;
    }

    public int getMovieId() {
        return movieId;
    }
    public String getMovieName() {
        return movieName;
    }
    public String getGenre() {
        return genre;
    }
}

class MovieService {
    public Map<Movie, Integer> movieMap = new HashMap<Movie, Integer>();

    public Map<Movie, Integer> getMovieMap() {
        return movieMap;
    }

    public void addMovie(Movie mov, int rating){
        movieMap.put(mov, rating);
        return;
    }

    public List<String> getHigherRatedMovieNames(int rating) {
        List<String> names = new ArrayList<String>();

        for (Map.Entry<Movie, Integer> entry : movieMap.entrySet())
        {
            if(entry.getValue() > 5){
                Movie mov = entry.getKey();
                names.add(mov.getMovieName());
            }
                
        }

        return names;
    }
}

public class Source3 {
    public static void main(String[] args) {
        Movie mov1 = new Movie(1, "Movie 1", "123");
        Movie mov2 = new Movie(2, "Movie 2", "123");
        Movie mov3 = new Movie(3, "Movie 3", "123");
        
        MovieService movieService = new MovieService();
        movieService.addMovie(mov1, 4);
        movieService.addMovie(mov2, 14);
        movieService.addMovie(mov3, 30);

        List<String> names = movieService.getHigherRatedMovieNames(10);
        for(String name : names){
            System.out.println(name);
        }
    }
}
