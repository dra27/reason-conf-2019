open Util;

[@bs.module] external scriptLogo : string = "../assets/script18-logo.svg";

let component = ReasonReact.statelessComponent("Home");

module Link = Gatsby.Link;

let speakerColumn = (speaker: Data.speakerData) =>
  <li className="speaker-list--item">
    <SpeakerCard speaker key=speaker.name />
  </li>;

let make = _children => {
  ...component,
  render: _self =>
    <article>
      <header className="teaser">
        <section className="container_centered grid grid-6col">
          <h1 className="teaser--logo">
            <img
              src=Assets.logo
              alt="Reason Conf 2018"
              className="teaser--image"
            />
          </h1>
          <nav className="teaser--navigation">
            <Navigation pathName="/" />
          </nav>
          <h2 className="teaser--dates">
            <time dateTime="2018-05-11/2018-05-13">
              ({j|11–13 May 2018|j} |> s)
            </time>
          </h2>
          <p className="teaser--location"> ("Vienna, Austria" |> s) </p>
          <p className="teaser--tagline">
            (
              {j|World’s first Reason conference for web-developers & OCaml enthusiasts|j}
              |> s
            )
          </p>
        </section>
      </header>
      <section className="offering">
        <div className="container_centered grid grid-6col">
          <h2 className="offering--heading">
            ("Get productive with Reason in 3 days" |> s)
          </h2>
          <section className="offering--text">
            <p>
              (
                {js|
                  Reason is the next big thing and it is time to bring
                  the community together. Come and learn about the
                  language and get inspired for innovation.
                |js}
                |> s
              )
            </p>
            <p>
              (
                {js|
                  We want to motivate you to add Reason & OCaml to
                  your professional toolbelt and make you
                  feel comfortable in the ecosystem.
                |js}
                |> s
              )
            </p>
            <p>
              (
                {js|
                  This conference is aiming for a well-balanced schedule
                  with a practical, social and theoretical context.
                |js}
                |> s
              )
            </p>
          </section>
          <dl className="timeline">
            <dt className="timeline--date">
              <time dateTime="2018-05-11">
                ("11" |> s)
                <sup> ("th" |> s) </sup>
                (" May, Friday" |> s)
              </time>
            </dt>
            <dd className="timeline--content">
              <h3> ("Day 1: Get started" |> s) </h3>
              <p>
                (
                  {js|
                    An optional workshop day to get every beginner and
                    intermediate attendee into the language &
                    platform.
                  |js}
                  |> s
                )
              </p>
            </dd>
            <dt className="timeline--date">
              <time dateTime="2018-05-12">
                ("12" |> s)
                <sup> ("th" |> s) </sup>
                (" May, Saturday" |> s)
              </time>
            </dt>
            <dd className="timeline--content">
              <h3> ("Day 2: Get inspired" |> s) </h3>
              <p>
                (
                  {js|
                    This is the main conference day with lectures and talks.
                    Speakers of the Reason / OCaml community (with special guests
                    from the Reason & ReasonReact project) will inspire attendees for
                    more advanced topics.
                  |js}
                  |> s
                )
              </p>
            </dd>
            <dt className="timeline--date">
              <time dateTime="2018-05-13">
                ("13" |> s)
                <sup> ("th" |> s) </sup>
                (" May, Sunday" |> s)
              </time>
            </dt>
            <dd className="timeline--content">
              <h3> ("Day 3: Get productive" |> s) </h3>
              <p>
                (
                  {js|
                    On the last day we encourage attendees to start
                    their first Reason projects, aided by our mentors,
                    speakers and volunteers. Alternatively for those
                    who want to relax, we offer a local-guided tour
                    through the beautiful city Vienna!
                  |js}
                  |> s
                )
              </p>
            </dd>
          </dl>
        </div>
      </section>
      <section className="speakers">
        <div className="container_centered">
          <h2> ("Featured Speakers" |> s) </h2>
          <ul className="speaker-list">
            (
              Data.headlineSpeakers
              |> Array.map(speakerColumn)
              |> ReasonReact.arrayToElement
            )
          </ul>
          <p className="speakerTeaser">
            (
              "... and many more to come. The finale schedule will be announced soon."
              |> s
            )
          </p>
        </div>
      </section>
      <section className="sponsors">
        <div className="container_centered">
          <h2> ("Sponsors & Partners" |> s) </h2>
          <div className="partners">
            <img src=scriptLogo className="scriptConf" />
          </div>
          <p> ({js||js} |> s) </p>
        </div>
      </section>
    </article>
};

let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));
