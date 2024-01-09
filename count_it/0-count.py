#!/usr/bin/env python3
"""Count It Module"""
import requests
import time


def count_words(subreddit, word_list):
    """Queries the Reddit API, parses the title of all hot articles, and
    prints a sorted count of given keywords (case-insensitive, delimited
    by spaces.)"""

    response = requests.get(f"https://www.reddit.com/r/{subreddit}/about.json")

    if response.status_code != 200:
        return

    base_url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    request = requests.get(base_url, headers={'User-agent': 'yourbot'})

    if request.status_code != 200:
        print(f"Error: {request.status_code}")
        return

    posts = []
    for post in request.json()['data']['children']:
        x = post['data']['title']
        posts.append(x)
    posts = ' '.join(posts).lower()
    print(posts)
    for word in word_list:
        matchings = posts.count(word.lower())
        if matchings > 0:
            print(f"{word}:", posts.count(word.lower()))
