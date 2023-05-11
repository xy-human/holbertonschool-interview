#!/usr/bin/python3
"""This module is in charge of making the connection with the
    api and parses the title of all hot articles, and prints a
    sorted count of given keywords."""
import requests


def process_subreddit(hot_subreddits, word_list):
    """This method parses the title of all hot articles,
        and prints a sorted count of given keywords."""
    list_all = {}

    if hot_subreddits is None:
        return

    lowered_words = list(map(lambda x: x.lower(), word_list))

    for word in lowered_words:
        total = 0
        for hot_subreddit in hot_subreddits:
            if word in hot_subreddit.lower():
                total += hot_subreddit.lower().split().count(word)
        if total > 0:
            if word not in list_all:
                list_all[word] = total
            else:
                list_all[word] += total

    result = sorted(list_all.items(), key=lambda x: x[0])
    result = sorted(result, key=lambda x: x[1], reverse=True)
    for k, v in result:
        print("{}: {}".format(k, v))


def count_words(subreddit, word_list, hot_list=[], after=""):
    """This method gets all hot articles for a given subreddit"""
    headers = {"user-agent": "1637-holberton"}

    if after is None:
        return process_subreddit(hot_list, word_list)

    if after == "":
        r = requests.get('https://www.reddit.com/r/{}/hot.json'.format(
            subreddit), headers=headers, allow_redirects=False)
    else:
        r = requests.get(
            'https://www.reddit.com/r/{}/hot.json?after={}'.format(
                subreddit, after), headers=headers, allow_redirects=False)

    if r.status_code != 200:
        return None

    after = r.json().get("data").get("after")

    for child in r.json().get("data").get("children"):
        hot_list.append(child.get("data").get("title"))

    return count_words(subreddit, word_list, hot_list, after)
