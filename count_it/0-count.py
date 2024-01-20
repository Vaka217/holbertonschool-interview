#!/usr/bin/python3
"""Count It Module"""
import requests

after = None


def recurrent_search(subreddit, hot_articles=[]):
    """Recursive function that queries the Reddit API and parses the title of
    all hot articles"""
    try:
        global after
        url = "https://www.reddit.com/r/"

        if after:
            response = requests.get(url + subreddit + "/hot.json?after=" +
                                    after, headers={
                                        'User-agent': 'yourbot'},
                                    allow_redirects=False)
        else:
            response = requests.get(url + subreddit + "/hot.json",
                                    headers={'User-agent': 'yourbot'},
                                    allow_redirects=False)

        after = response.json()["data"]["after"]
        hot_articles += [article["data"]["title"]
                         for article in response.json()["data"]["children"]]

        if after:
            recurrent_search(subreddit, hot_articles)

        return hot_articles
    except Exception:
        return None


def count_words(subreddit, word_list):
    """Prints a sorted count of given keywords (case-insensitive, delimited
    by spaces).
    Results should be printed in descending order, by the count, and if the
    count is the same for separate keywords, they should then be sorted
    alphabetically (ascending, from A to Z).
    Words with no matches should be skipped and not printed. Words must be
    printed in lowercase.
    Results are based on the number of times a keyword appears, not titles it
    appears in. java java java counts as 3 separate occurrences of java.
    To make life easier, java. or java! or java_ should not count as java
    If no posts match or the subreddit is invalid, print nothing."""
    hot_articles = recurrent_search(subreddit)

    if hot_articles is None:
        return None

    count = {word: 0 for word in word_list}
    for article in hot_articles:
        for word in word_list:
            if word.lower() in article:
                count[word] += 1

    count_sorted = sorted(count.items(),
                          key=lambda x: x[0])
    count_sorted = sorted(count_sorted,
                          key=lambda x: x[1], reverse=True)

    for word in count_sorted:
        if word[1] > 0:
            print("{}: {}".format(word[0], word[1]))
